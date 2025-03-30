#ifndef HeavySnow_FACTORY_H_
#define HeavySnow_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "HeavySnow.h"

/**
 *@brief HeavySnow Factory to produce HeavySnow class.
 **/
class HeavySnowFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for HeavySnowFactory class.
   **/
  virtual ~HeavySnowFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
