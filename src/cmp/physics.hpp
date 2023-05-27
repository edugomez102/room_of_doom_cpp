#pragma once 

#include <uage/math_types.hpp>

namespace rod {

  struct PhysicsComponent {
    uage::Vec2Df pos{};
    uage::Vec2Df vel{};
  };
}
