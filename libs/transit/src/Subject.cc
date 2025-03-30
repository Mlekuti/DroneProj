// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example
#include <iostream>
#include "Subject.h"

Subject::~Subject() {
  std::cout << "Subject is deleted\n";
}

void Subject::Attach(IObserver *observer) {
  list_observer_.push_back(observer);
}

void Subject::Detach(IObserver *observer)  {
  list_observer_.remove(observer);
}

void Subject::Notify() {
  std::list<IObserver *>::iterator iterator = list_observer_.begin();
  HowManyObserver();
  while (iterator != list_observer_.end()) {
    (*iterator)->Update(weatherStateChangedTo);
    ++iterator;
  }
}

void Subject::CreateMessage(std::string weatherStateChangedTo) {
  this->weatherStateChangedTo = weatherStateChangedTo;
  Notify();
}

void Subject::HowManyObserver() {
  std::cout << "There are " << list_observer_.size()
  << " observers in the list.\n";
}
