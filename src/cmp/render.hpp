#pragma once 

#include <uage/sprite.hpp>

namespace rod {
  struct RenderComponent {
    uage::Sprite sprite{};
    uage::Vec2D pos{};
  };
}
