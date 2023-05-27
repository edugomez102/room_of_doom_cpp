
#include "screenbuffer.hpp"
#include "math_types.hpp"

#include <cstdint>

uint32_t spritea[4 * 4] = {
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
};

namespace uage {

  ScreenBuffer::ScreenBuffer(const uint32_t w, const uint32_t h)
    : dim_{w, h}
  { 
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void ScreenBuffer::fill(const uint32_t hexColor)
  {
    std::fill(data_.begin(), data_.end(), hexColor);
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void ScreenBuffer::drawSprite(const Sprite& sprite, const Vec2D& position)
  {
    if(position.x > dim_.w || position.y > dim_.h) return; // TODO

    auto spdim = sprite.dim();
    uint32_t* pscr = data_.data() + position.x + (position.y * dim_.w);
    const uint32_t* psp  = sprite.data();

    for (uint32_t i = 0; i < spdim.w; i++) {
      for (uint32_t j = 0; j < spdim.h; j++) {
        *pscr = *psp;
        ++pscr;
        ++psp;
      }
      pscr += dim_.w - (spdim.w) + (spdim.w - spdim.h);
    }
  }

}
