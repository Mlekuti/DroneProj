#ifndef Sunny_H_
#define Sunny_H_

#include "IEntity.h"
#include "IStrategy.h"

class Sunny : public IEntity {
 public:
  /**
   * @brief Sunny entity is created with a name
   * @param obj JSON object containing the Sunny's information
   */
  Sunny(JsonObject& obj);

  /**
 * @brief The Sunny deconstructor.
 * 
 * @return Nothing. The instance is deleted.
 **/
  ~Sunny();

/**
 * @brief The pure virtual function implementation.
 * 
 * @param dt The time as a double.
 * @return Nothing.
 **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
