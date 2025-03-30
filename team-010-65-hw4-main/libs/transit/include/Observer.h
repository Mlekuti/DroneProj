// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example
#ifndef OBSERVER_H_
#define OBSERVER_H_

#include "IObserver.h"
#include "Subject.h"

    /**
 * @brief The Observer class.
 * 
 **/
class Observer : public IObserver{
 public:
     /**
 * @brief The Observer class constructor.
 * 
 * @param subject The subject class instance to be "observed"
 * @return An instance of the Observer class is created.
 **/
  Observer(Subject &subject);

    /**
 * @brief The Observer class deconstructor.
 * 
 * @return Nothing. Instance is deleted.
 **/
  virtual ~Observer();

    /**
 * @brief Update function. Used to update the Observer with a string value.
 * 
 * @param message_from_subject This is the message to update the Observer with, taken as a string.
 * @return Nothing. The observer is updated.
 **/
  void Update(const std::string &message_from_subject) override;

    /**
 * @brief Function to remove the Observer from the list.
 * 
 * @return Nothing. Instance is removed from the list.
 **/
  void RemoveMeFromTheList();

    /**
 * @brief Function to print info about the Observer instance.
 * 
 * @return Nothing. Key information about the Observer instance is printed out.
 **/
  void PrintInfo();

 private:
  std::string message_from_subject_;
  Subject &subject_;
  static int static_number_;
  int number_;
};

#endif
