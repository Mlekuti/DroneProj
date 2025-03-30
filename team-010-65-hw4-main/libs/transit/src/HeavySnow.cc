#define _USE_MATH_DEFINES
#include "HeavySnow.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "SimulationModel.h"

HeavySnow::HeavySnow(JsonObject& obj) : IEntity(obj) {}

HeavySnow::~HeavySnow() {
  if (movement) delete movement;
}

void HeavySnow::update(double dt) {}
