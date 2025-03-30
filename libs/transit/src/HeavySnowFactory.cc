#include "HeavySnowFactory.h"

IEntity* HeavySnowFactory::CreateEntity(JsonObject& entity) {
  std::string type = entity["type"];
  if (type.compare("HEAVYSNOW") == 0) {
    std::cout << "Heavysnow Background Created" << std::endl;
    return new HeavySnow(entity);
  }
  return nullptr;
}
