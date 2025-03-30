// C++ design pattern used from: https://refactoring.guru/design-patterns/observer/cpp/example
#include "Observer.h"
#include <iostream>

int Observer::static_number_ = 0;

Observer::Observer(Subject &subject) : subject_(subject) {
  this->subject_.Attach(this);
  std::cout << "Observer instance created\""
  << ++Observer::static_number_ << "\".\n";
  this->number_ = Observer::static_number_;
}

Observer::~Observer() {
  std::cout << "Observer instance deleted\"" << this->number_ << "\".\n";
}

void Observer::Update(const std::string &message_from_subject) {
  message_from_subject_ = message_from_subject;
  PrintInfo();
}

void Observer::RemoveMeFromTheList() {
  subject_.Detach(this);
  std::cout << "Observer \"" << number_ << "\" removed from the list.\n";
}

void Observer::PrintInfo() {
  std::cout << "Observer \"" << this->number_
  << "\": a new message is available --> "
  << this->message_from_subject_ << "\n";
}
