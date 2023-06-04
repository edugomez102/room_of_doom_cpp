#include "spriteman.hpp"

namespace rod {

  uage::Sprite
  rod::SpriteManager::createSprite(SpriteType spt)
  {
    switch (spt) {

      case SpriteType::Player:
        return spritesheet_.new_subsprite({{0,0},{16,32}});
        break;

      case SpriteType::Enemy:
        return spritesheet_.new_subsprite({{16,0},{16,32}});
        break;
    }
  }
}
