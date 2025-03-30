#ifndef Tornado_FACTORY_H_
#define Tornado_FACTORY_H_

#include <vector>

#include "IEntityFactory.h"
#include "Tornado.h"

/**
 *@brief Tornado Factory to produce Tornado class.
 **/
class TornadoFactory : public IEntityFactory {
 public:
  /**
   * @brief Destructor for TornadoFactory class.
   **/
  virtual ~TornadoFactory() {}

  /**
   * @brief Creates entity using the given JSON object, if possible.
   * @param entity - JsonObject to be used to create the new entity.
   * @return Entity that was created if it was created successfully, or a
   *nullpointer if creation failed.
   **/
  IEntity* CreateEntity(JsonObject& entity);
};

#endif
