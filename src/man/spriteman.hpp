#pragma once 

#include <uage/sprite.hpp>

namespace rod {

  enum class SpriteType {
    Player,
    Enemy,
  };

  struct SpriteManager{

    explicit SpriteManager(const std::filesystem::path& path)
      :spritesheet_{path}
    {
    }

    // uage::Sprite createSprite(SpriteType spt);

    private:
      uage::Sprite spritesheet_{};

      std::vector<uage::Sprite> cached{};
  };
}
