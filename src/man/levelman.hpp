#pragma once 

#include <cmp/entity.hpp>
#include <man/entityman.hpp>
#include <man/spriteman.hpp>
#include <memory>

namespace rod {

  using EntityManager = uage::EntityManager<Entity>;

  struct LevelManager {
    EntityManager& EntMan() { return EM_;}

    void createShot(const uage::Vec2Df pos, const uage::Vec2Df vel);

    void startTestLevel();
    
    private:
      EntityManager EM_{10};
      // SpriteManager SM_{};
      // TODO sprite man
  };
}
