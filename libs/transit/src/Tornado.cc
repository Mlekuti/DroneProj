#define _USE_MATH_DEFINES
#include "Tornado.h"

#include <cmath>
#include <limits>

#include "DfsStrategy.h"
#include "SimulationModel.h"

Tornado::Tornado(JsonObject& obj) : IEntity(obj) {}

Tornado::~Tornado() {
  if (movement) delete movement;
}

void Tornado::update(double dt) {
  dt = dt + 0.1;
  if (movement && !movement->isCompleted()) {
    movement->move(this, dt);
  } else {
    if (movement) delete movement;
    Vector3 dest;
    dest.x = ((static_cast<double>(rand())) / RAND_MAX) * (2900) - 1400;
    dest.y = position.y;
    dest.z = ((static_cast<double>(rand())) / RAND_MAX) * (1600) - 800;
    if (model)
      movement = new DfsStrategy(position, dest, model->getGraph());
  }
}
