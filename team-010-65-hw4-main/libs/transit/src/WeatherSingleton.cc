#include "WeatherSingleton.h"

#include <iostream>
#include <string>


WeatherSingleton* WeatherSingleton::instance = nullptr;
// still not thread safe? Think it doesn't matter
WeatherSingleton* WeatherSingleton::getInstance() {
  if (!instance) instance = new WeatherSingleton;
  return instance;
}

void WeatherSingleton::changeState(std::string newState) {
  // 0 state is sunny
  // 1 state is heavy rain
  // 2 state is heavy snow
  // 3 state is tornado
  if (newState == "SUNNY") {
    this->state = 0;
    std::cout << "Debug::Singleton Sunny Activated "
              << "\n";

  } else if (newState == "HEAVYRAIN") {
    this->state = 1;
    std::cout << "Debug::Singleton Heavy Rain Activated "
              << "\n";

  } else if (newState == "HEAVYSNOW") {
    this->state = 2;
    std::cout << "Debug::Singleton Heavy Snow Activated"
              << "\n";

  } else if (newState == "TORNADO") {
    this->state = 3;
    std::cout << "Debug::Singleton Tornado Activated "
              << "\n";
  }
}
int WeatherSingleton::getWeatherPattern() const { return this->state; }

WeatherSingleton::WeatherSingleton() {
  // default weather pattern
  this->state = 0;
}
