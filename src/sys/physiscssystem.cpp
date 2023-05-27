#include "physiscssystem.hpp"

namespace rod {

  void 
  PhysicsSystem::update(EntityManager& EM) {
    for (Entity& e : EM) {
      if(e.physics) {
        e.physics->pos += e.physics->vel;
      }
    }
  }

}
