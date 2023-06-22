#pragma once 

#include <cmp/entity.hpp>
#include <man/entityman.hpp>
#include <man/spriteman.hpp>
#include <memory>

namespace rod {

  using EntityManager = uage::EntityManager<Entity>;

  struct LevelManager {

    LevelManager() = default;

    LevelManager(size_t storage);

    EntityManager& EntMan() { return EM_;}

    void createShot(const uage::Vec2Df pos, const uage::Vec2Df vel);

    void startTestLevel();
    
    private:
      EntityManager EM_{10};

      // TODO optional path
      SpriteManager SprM_{"assets/img/sprite_sheet_01.png"};
  };
}
