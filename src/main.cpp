extern "C" {
#include "tinyPTC/tinyptc.h"
}
#include <cstdint>

#include "uage/sprite.hpp"
#include "uage/screenbuffer.hpp"

uint32_t screen[640 * 360];

uint32_t sprite[4 * 4] = {
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
};


const uint32_t w = 640;
const uint32_t h = 456;

int main()
{
  ptc_open("window", w, h);

  uage::ScreenBuffer screen{w, h};
  screen.fill(0x00FF00FF);

  auto rect = uage::Sprite({4, 4}, 0x000000FF);

  // screen.drawSprite(uage::Sprite{}, {0, 10});

  while( ! ptc_process_events())
  {
    // fill(screen, 0x00FF0000);
    // drawSprite(screen, sprite);

    screen.drawSprite(rect, {20, 10});
    ptc_update(screen.data());
  }

  ptc_close();

  return 0;
}
