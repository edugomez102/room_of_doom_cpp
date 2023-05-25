#pragma once 

#include <cstdint>

namespace uage {

  struct Dimensions2D {

    uint32_t w{0};
    uint32_t h{0};

    uint32_t size() const { return w * h;}

  };

  // TODO
  struct Vec2D {
    uint32_t x{};
    uint32_t y{};

  };

  struct Rect2D {
    Vec2D pos{};
    Dimensions2D dim{};

  };

}
