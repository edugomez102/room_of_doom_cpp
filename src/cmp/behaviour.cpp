#include "behaviour.hpp"
#include "entity.hpp"

namespace rod {

  void BehaviourBounce::run(rod::Entity& e) {
    if (e.physics) {
      auto& phy = *e.physics;

      if(phy.pos.x <= 0)   { phy.pos.x =   0; phy.vel.x = - phy.vel.x; }
      if(phy.pos.y <= 0)   { phy.pos.y =   0; phy.vel.y = - phy.vel.y; }
      if(phy.pos.x >= 640) { phy.pos.x = 640; phy.vel.x = - phy.vel.x; }
      if(phy.pos.y >= 456) { phy.pos.y = 456; phy.vel.y = - phy.vel.y; }
    }
  }

  void BehaviourChangeVY::run(rod::Entity& e){
    if(e.physics){
      auto& phy = *e.physics;
      if(counter == 0)
      {
        phy.vel.y = - phy.vel.y;
        counter = initial_count;
      }
      else --counter;
    }
  };

}
