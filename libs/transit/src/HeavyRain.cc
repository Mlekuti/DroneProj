#define _USE_MATH_DEFINES
#include "HeavyRain.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "SimulationModel.h"

HeavyRain::HeavyRain(JsonObject& obj) : IEntity(obj) {}

HeavyRain::~HeavyRain() {
  if (movement) delete movement;
}

void HeavyRain::update(double dt) {}
