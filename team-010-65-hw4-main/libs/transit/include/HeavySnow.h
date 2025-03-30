#ifndef HeavySnow_H_
#define HeavySnow_H_

#include "IEntity.h"
#include "IStrategy.h"

class HeavySnow : public IEntity {
 public:
  /**
   * @brief HeavySnow are created with a name
   * @param obj JSON object containing the HeavySnow's information
   */
  HeavySnow(JsonObject& obj);

/**
 * @brief The HeavySnow Deconstructor.
 * 
 * @return Nothing. The HeavySnow instance is deleted.
 **/
  ~HeavySnow();

/**
 * @brief The pure virtual function implementation.
 * 
 * @param dt Time as a double.
 * @return Nothing.
 **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
