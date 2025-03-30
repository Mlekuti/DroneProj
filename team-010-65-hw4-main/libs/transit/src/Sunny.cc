#define _USE_MATH_DEFINES
#include "Sunny.h"

#include <cmath>
#include <limits>

#include "AstarStrategy.h"
#include "SimulationModel.h"

Sunny::Sunny(JsonObject& obj) : IEntity(obj) {}

Sunny::~Sunny() {
  if (movement) delete movement;
}

void Sunny::update(double dt) {}
