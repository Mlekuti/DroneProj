#include "TornadoFactory.h"

IEntity* TornadoFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("TORNADO") == 0) {
    std::cout << "Tornado Created" << std::endl;
    return new Tornado(entity);
  }
  return nullptr;
}
