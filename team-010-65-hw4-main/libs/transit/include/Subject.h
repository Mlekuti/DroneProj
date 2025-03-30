// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example
#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <list>
#include "ISubject.h"
#include "IObserver.h"

  /**
 * @brief The Subject class.
 * 
 * @return A new instance of the Subject class is created.
 **/
class Subject : public ISubject {
 public:
    /**
 * @brief The Subject class deconstructor.
 * 
 * @return Nothing. Instance is deleted.
 **/
  virtual ~Subject();

    /**
 * @brief Function used to attach an IObserver instance to the Subject instance.
 * 
 * @param observer The IObserver instance to be attached.
 * @return Nothing. IObserver instance is attached.
 **/
  void Attach(IObserver *observer) override;

    /**
 * @brief Function used to detach an IObserver instance from the Subject instance.
 * 
 * @param observer The IObserver instance to be detached.
 * @return Nothing. IObserver instance is detached.
 **/
  void Detach(IObserver *observer) override;

    /**
 * @brief Function to notify the observer.
 * 
 * @return Nothing. Observer is notified.
 **/
  void Notify() override;

    /**
 * @brief Function to create a message as a string Default is "None".
 * 
 * @param weatherStateChangedTo The new weather state taken as a string.
 * @return Nothing. Message is created.
 **/
  void CreateMessage(std::string weatherStateChangedTo = "None");

    /**
 * @brief Function to obtain the number of current observers.
 * 
 * @return Nothing.
 **/
  void HowManyObserver();

 private:
  std::list<IObserver *> list_observer_;
  std::string weatherStateChangedTo;
};

#endif
