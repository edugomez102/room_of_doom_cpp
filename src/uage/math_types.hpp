#pragma once 

#include <cstdint>

namespace uage {

  template <typename T>
  struct Vec2D_t {
    T x{}, y{};

    Vec2D_t& operator+=(const Vec2D_t rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec2D_t& operator-=(const Vec2D_t rhs) { x -= rhs.x; y -= rhs.y; return *this; }
  };

  using Vec2D = Vec2D_t<uint32_t>;

  struct Dimensions2D {
    uint32_t w{}, h{};

    uint32_t size() const { return w * h;}

  };


  struct Rect2D {
    Vec2D pos{};
    Dimensions2D dim{};

  };

}
