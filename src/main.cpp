extern "C" {
#include "tinyPTC/tinyptc.h"
}
#include <cstdint>

#include "uage/sprite.hpp"
#include "uage/screenbuffer.hpp"

constexpr uint32_t w = 640;
constexpr uint32_t h = 456;

int main()
{
  ptc_open("window", w, h);

  uage::ScreenBuffer screen{w, h};
  screen.fill(0x00FF00FF);
  auto rect = uage::Sprite({24, 24}, 0x000000FF);

  while( ! ptc_process_events())
  {
    // fill(screen, 0x00FF0000);
    // drawSprite(screen, sprite);

    screen.drawSprite(rect, {2, 2});

    ptc_update(screen.data());
  }

  ptc_close();

  return 0;
}
