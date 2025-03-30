#include "HeavyRainFactory.h"

IEntity* HeavyRainFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("HEAVYRAIN") == 0) {
    std::cout << "Heavy Rain Created" << std::endl;
    return new HeavyRain(entity);
  }
  return nullptr;
}
