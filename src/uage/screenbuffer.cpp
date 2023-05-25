
#include "screenbuffer.hpp"
#include "math_types.hpp"

#include <cstdint>

namespace uage {

  ScreenBuffer::ScreenBuffer(const uint32_t w, const uint32_t h)
    : dim_{w, h}
  { 
  }

  void ScreenBuffer::fill(const uint32_t hexColor)
  {
    std::fill(data_.begin(), data_.end(), hexColor);
  }

  uint32_t spritea[4 * 4] = {
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  };

  void ScreenBuffer::drawSprite(const Sprite& sprite, const Vec2D& position)
  {
    // auto spdim = sprite.dim();
    auto spdim = uage::Dimensions2D{16, 16};

    uint32_t* pscr = data_.data() + position.x + (position.y * dim_.w);
    const uint32_t* psp  = sprite.data();

    for (uint32_t i = 0; i < spdim.w; i++) {
      for (uint32_t j = 0; j < spdim.h; j++) {

        *pscr = 0xFFFF0000;
        // *pscr = *psp;
        ++pscr;
        ++psp;
      }
      pscr += dim_.w - spdim.w ;
    }
  }

}
