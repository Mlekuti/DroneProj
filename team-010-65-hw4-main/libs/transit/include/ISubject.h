// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example
#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "IObserver.h"

  /**
 * @brief The ISubject Class.
 * 
 * @return An instance of the ISubject class is created.
 **/
class ISubject {
 public:
    /**
 * @brief The ISubject deconstructor.
 * 
 * @return Nothing. Instance is deleted.
 **/
  virtual ~ISubject() {}

    /**
 * @brief IObserver instance attaching function.
 * 
 * @return Nothing. Instance is attached.
 **/
  virtual void Attach(IObserver *observer) = 0;

    /**
 * @brief IObserver instance detaching function.
 * 
 * @return Nothing. Instance is detached.
 **/
    virtual void Detach(IObserver *observer) = 0;

    /**
 * @brief ISubject notifying function.
 * 
 * @return Nothing.
 **/
  virtual void Notify() = 0;
};
#endif
