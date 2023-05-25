
#include "sprite.hpp"

namespace uage {

  Sprite::Sprite(Dimensions2D dim, uint32_t color)
    : dim_{dim}
    , data_{std::vector<uint32_t>(dim.size(), color)}
  {
  }

}
