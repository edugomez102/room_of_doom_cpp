
#include "screenbuffer.hpp"
#include "math_types.hpp"

#include <cstdint>
#include <algorithm>

constexpr uint32_t spritea[5 * 4] = {
  // 0x00FF0000, 0x0000FF00

  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000, 0x000000FF,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000, 0x000000FF,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000, 0x000000FF,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000, 0x000000FF,

  // 0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  // 0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  // 0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  // 0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF00FF,

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

  ScreenBuffer::ClippedRect calculateSpriteClipping(const Sprite& sprite, const Vec2D& screenPosition)
  {
    return ScreenBuffer::ClippedRect{};
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void ScreenBuffer::drawSprite(const Sprite& sprite, const Vec2D& position)
  {
    // TODO
    if(uint32_t(position.x) + sprite.dim().w > dim_.w ||
       uint32_t(position.y) + sprite.dim().h > dim_.h ||
       position.x < 0 || position.y < 0)
      return; 

    auto spdim = sprite.dim();
    const uint32_t* p_sprite = sprite.data();
    uint32_t* p_screen = data_.data() + position.x + (uint32_t(position.y) * dim_.w);

    for (uint32_t i = 0; i < spdim.h; ++i) {
      std::copy(p_sprite, p_sprite + spdim.w, p_screen);
      p_sprite  += spdim.w;
      p_screen  += dim_.w;
    }
  }
}
