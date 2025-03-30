#ifndef HeavyRain_FACTORY_H_
#define HeavyRain_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "HeavyRain.h"

/**
 *@brief Heavy Rain Factory to produce Heavy Rain class.
 **/
class HeavyRainFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for HeavyRainFactory class.
   **/
  virtual ~HeavyRainFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
