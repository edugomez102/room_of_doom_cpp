#pragma once 

#include <cstdint>

namespace uage {

  template <typename T>
  struct Vec2D_t {
    T x{}, y{};

    Vec2D_t& operator+=(const Vec2D_t rhs) { x += rhs.x; y += rhs.y; return *this; }
    Vec2D_t& operator-=(const Vec2D_t rhs) { x -= rhs.x; y -= rhs.y; return *this; }
  };

  // default
  using Vec2D  = Vec2D_t<int32_t>;
  using Vec2Df = Vec2D_t<float>;

  struct Dimensions2D {
    uint32_t w{}, h{};

    uint32_t size() const { return w * h;}

  };

  struct Rect2D {

    Vec2D pos{};
    Dimensions2D dim{};

    // bool operator<=>(const Rect2D&) const noexcept = default;

  };

}
