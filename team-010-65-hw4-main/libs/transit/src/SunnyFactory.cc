#include "SunnyFactory.h"

IEntity* SunnyFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("SUNNY") == 0) {
    std::cout << "Sunny Background Created" << std::endl;
    return new Sunny(entity);
  }
  return nullptr;
}
