#ifndef WEATHER_SINGLETON_H
#define WEATHER_SINGLETON_H
#include <string>

/**
 * @brief The WeatherSingleton class.
 * 
 * @return Nothing.
 **/
class WeatherSingleton {
 public:
 /**
 * @brief Allows you to retrieve an instance of the Weather Singleton.
 * 
 * @return The WeatherSingleton instance.
 **/
  static WeatherSingleton* getInstance();

  /**
 * @brief This function changes the current state of the weather.
 * 
 * @param newState The new state to be set.
 * @return Nothing.
 **/
  void changeState(std::string newState);

/**
 * @brief This function provides the current Weather pattern.
 * 
 * @return The current weather pattern as an integer.
 **/
  int getWeatherPattern() const;

 private:
/**
 * @brief The WeatherSingleton constructor.
 * 
 * @return A newly created instance of the WeatherSingleton.
 **/
  WeatherSingleton();
  static WeatherSingleton* instance;
  // 0 state is sunny
  // 1 state is heavy rain
  // 2 state is heavy snow
  // 3 state is tornado
  // keeps track of the type of weather we are having
  int state;

/**
 * @brief The WeatherSingleton deconstructors.
 * 
 * @param WeatherSingleton The instance to be deleted.
 * @return Nothing. The instance is deleted.
 **/
  WeatherSingleton(WeatherSingleton const&) = delete;
  void operator=(WeatherSingleton const&) = delete;
};
#endif
