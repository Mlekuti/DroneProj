#ifndef Sunny_FACTORY_H_
#define Sunny_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Sunny.h"

/**
 *@brief Sunny Factory to produce Sunny class.
 **/
class SunnyFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for SunnyFactory class.
   **/
  virtual ~SunnyFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
