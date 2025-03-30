#ifndef Helicopter_H_
#define Helicopter_H_

#include "IEntity.h"
#include "IStrategy.h"

class Helicopter : public IEntity {
 public:
  /**
   * @brief Helicopter are created with a name
   * @param obj JSON object containing the drone's information
   */
  Helicopter(JsonObject& obj);

  /**
 * @brief The Helicopter deconstructor.
 * 
 * @return Nothing. The instance is deleted.
 **/
  ~Helicopter();

/**
 * @brief Pure virtual function implementation.
 * 
 * @param dt The time as a double.
 * @return Nothing.
 **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
