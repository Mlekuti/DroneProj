#include <map>
#include <chrono>
#include "WebServer.h"
#include "SimulationModel.h"
#include "routing_api.h"
#include "WeatherSingleton.h"
#include "Observer.h"
#include "Subject.h"


//--------------------  Controller ----------------------------

/// A Transit Service that communicates with a web page through web sockets.  It also acts as the controller
/// in the model view controller pattern.
class TransitService : public JsonSession, public IController {
public:
    TransitService(SimulationModel& model) : model(model), start(std::chrono::system_clock::now()), time(0.0) {
        routing::RoutingAPI api;
        routing::IGraph* graph = api.LoadFromFile("libs/routing/data/umn.osm");
        model.setGraph(graph);
    }

    /// Handles specific commands from the web server
    void receiveCommand(const std::string& cmd, JsonObject& data, JsonObject& returnValue) {
        // std::cout << cmd << ": " << data << std::endl;
        // variable used to keep track of current entity
        if (cmd == "CreateEntity") {
               model.createEntity(data);
            // std::cout << prevEntity->getId() << std::endl;
        }
        else if (cmd == "ScheduleTrip") {
            model.scheduleTrip(data);
        }
        else if (cmd == "ping") {
            returnValue["response"] = data;
        }
        else if (cmd == "Update") {
            updateEntites.clear();

            std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
            std::chrono::duration<double> diff = end - start;
            double delta = diff.count() - time;
            time += delta;

            double simSpeed = data["simSpeed"];
            delta *= simSpeed;

            // Now checking WeatherSingleton instance to update speed according to the weather
            if (WeatherSingleton::getInstance()->getWeatherPattern() == 0){
                // std::cout << "1 speed change" << std::endl;
            }
            else if (WeatherSingleton::getInstance()->getWeatherPattern() == 1){
                // std::cout << "1/2 speed change" << std::endl;
                delta = delta/2;
            }
            else if (WeatherSingleton::getInstance()->getWeatherPattern() == 2){
                // std::cout << "1/4 speed change" << std::endl;
                delta = delta/4;
            }
            else if (WeatherSingleton::getInstance()->getWeatherPattern() == 3){
                // std::cout << "stop speed" << std::endl;
                delta = 0;
            }

            if (delta > 0.1) {
                for (float f = 0.0; f < delta; f+=0.01) {
                    model.update(0.01);
                }
            }
            else {
                model.update(delta);
            }

            for (auto& [id, entity] : updateEntites) {
                sendEntity("UpdateEntity", *entity);
            }
        }
        else if (cmd == "stopSimulation")
        {
            std::cout << "Stop command administered\n";
            model.stop();
        }
        else if (cmd == "updateWeather")
        {            
            static IEntity* prevWeatherEntity = nullptr;
            Subject *subject = new Subject;
            Observer *observer1 = new Observer(*subject);
            // first removing glb and then changing
            if (prevWeatherEntity != nullptr){
                // std::cout << "REMOVING #" << prevWeatherEntity->getId() << std::endl;

                model.removeEntity(prevWeatherEntity->getId());
            }
            prevWeatherEntity = model.createEntity(data);
            // std::cout << data["type"] << std::endl;
            // std::cout << prevWeatherEntity->getId() << std::endl;
            WeatherSingleton::getInstance()->changeState(data["type"]);
            subject->CreateMessage(data["type"]);
            JsonObject details;
            details["id"] = WeatherSingleton::getInstance()->getWeatherPattern();
            sendEventToView("FrontEndMessage", details);
            delete observer1;
            delete subject;

        
    }
    }
    void sendEntity(const std::string& event, const IEntity& entity, bool includeDetails = true) {
        //JsonObject details = entity.GetDetails();
        JsonObject details;
        if (includeDetails) {
            details["details"] = entity.getDetails();
        }
        details["id"] = entity.getId();
        Vector3 pos_ = entity.getPosition();
        Vector3 dir_ = entity.getDirection();
        JsonArray pos = {pos_.x, pos_.y, pos_.z};
        JsonArray dir = {dir_.x, dir_.y, dir_.z};
        details["pos"] = pos;
        details["dir"] = dir;
        std::string col_ = entity.getColor();
        if(col_ != "") details["color"] = col_;
        sendEventToView(event, details);
    }

    void addEntity(const IEntity& entity) {
        sendEntity("AddEntity", entity, true);
    }
    
    void updateEntity(const IEntity& entity) {
        updateEntites[entity.getId()] = &entity;
    }

    void removeEntity(const IEntity& entity) {
        JsonObject details;
        details["id"] = entity.getId();
        updateEntites.erase(entity.getId());
        sendEventToView("RemoveEntity", details);
    }

    /// Allows messages to be passed back to the view
    void sendEventToView(const std::string& event, const JsonObject& details) {
        JsonObject eventData;
        eventData["event"] = event;
        eventData["details"] = details;
        sendMessage(eventData.toString());
    }

    void stop() {}

    bool isAlive(){ return true; }

private:
    // Simulation Model
    SimulationModel& model;
    // Used for tracking time since last update
    std::chrono::time_point<std::chrono::system_clock> start;
    // The total time the server has been running.
    double time;
    // Current entities to update
    std::map<int, const IEntity*> updateEntites;
};


//--------------------  View / Web Server Code ----------------------------

/// The TransitWebServer holds the simulation and updates sessions.
class TransitWebServer : public WebServerBase, public IController {
public:
	TransitWebServer(int port = 8081, const std::string& webDir = ".") : WebServerBase(port, webDir), model(*this), alive_(true) {}
    void addEntity(const IEntity& entity) {
        for (int i = 0; i < sessions.size(); i++) {
            static_cast<TransitService*>(sessions[i])->addEntity(entity);
        }
    }
    
    void updateEntity(const IEntity& entity) {
        for (int i = 0; i < sessions.size(); i++) {
            static_cast<TransitService*>(sessions[i])->updateEntity(entity);
        }
    }

    void removeEntity(const IEntity& entity) {
        for (int i = 0; i < sessions.size(); i++) {
            static_cast<TransitService*>(sessions[i])->removeEntity(entity);
        }
    }

    void sendEventToView(const std::string& event, const JsonObject& details) {
        for (int i = 0; i < sessions.size(); i++) {
            static_cast<TransitService*>(sessions[i])->sendEventToView(event, details);
        }
    }

    void stop() { alive_ = false; }
    bool isAlive() { return alive_; }

protected:
	Session* createSession() { return new TransitService(model); }
private:
    SimulationModel model;
    bool alive_;
};

/// The main program that handles starting the web sockets service.
int main(int argc, char**argv) {
    if (argc > 1) {
        int port = std::atoi(argv[1]);
        std::string webDir = std::string(argv[2]);
        TransitWebServer server(port, webDir);
        while (server.isAlive()) {
            server.service();
        }
    }
    else {
        std::cout << "Usage: ./build/bin/transit_service <port> apps/transit_service/web/" << std::endl;
    }

    return 0;
}

