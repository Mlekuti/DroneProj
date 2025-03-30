#ifndef HeavyRain_H_
#define HeavyRain_H_
#include "IEntity.h"
#include "IStrategy.h"

class HeavyRain : public IEntity {
 public:
  /**
   * @brief Heavy Rain is created with a name
   * @param obj JSON object containing the Heavy Rain's information
   */
  HeavyRain(JsonObject& obj);

  /**
 * @brief The HeavyRain Deconstructor.
 * 
 * @return Nothing. Instance is deleted.
 **/
  ~HeavyRain();

/**
 * @brief Pure virtual function implementation.
 * 
 * @param dt Time as a double.
 * @return Nothing.
 **/
  void update(double dt);

 private:
  IStrategy* movement = nullptr;
};

#endif
