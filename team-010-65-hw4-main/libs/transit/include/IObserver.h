// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example

#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include <list>
#include <iostream>


  /**
 * @brief The Observer Class.
 * 
 * @return An instance of the IObserver class.
 **/
class IObserver {
 public:
    /**
 * @brief The IObserver class deconstructor.
 * 
 * @return Nothing. Instance is deleted.
 **/
  virtual ~IObserver() {}

  /**
 * @brief Update function for the Observer.
 * 
 * @return Nothing. Instance is updated.
 **/
  virtual void Update(const std::string &subject_message) = 0;
};
#endif
