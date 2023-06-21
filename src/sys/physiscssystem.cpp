#include "physiscssystem.hpp"
#include <man/levelman.hpp>

namespace rod {

  void 
  PhysicsSystem::update(LevelManager& LevMan) {
    auto& EM = LevMan.EntMan();
    for (Entity& e : EM) {
      if(e.physics) {
        e.physics->pos += e.physics->vel;
      }
    }
  }

}
