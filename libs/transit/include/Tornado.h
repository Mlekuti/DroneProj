#ifndef Tornado_H_
#define Tornado_H_

#include "IEntity.h"
#include "IStrategy.h"

class Tornado : public IEntity {
 public:
  /**
   * @brief Tornado is created with a name
   * @param obj JSON object containing the Tornado's information
   */
  Tornado(JsonObject& obj);

/**
 * @brief The tornado deconstructor.
 * 
 * @return Nothing. The instance is deleted.
 **/
  ~Tornado();

/**
 * @brief The pure virtual update function implementation.
 * 
 * @param dt The time as a double.
 * @return Nothing.
 **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
