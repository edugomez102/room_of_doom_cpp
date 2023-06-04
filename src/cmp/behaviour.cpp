#include "behaviour.hpp"
#include "entity.hpp"
#include <man/levelman.hpp>

namespace rod {

  void 
  BehaviourBounce::run(rod::Entity& e, LevelManager&) {
    if (e.physics) {
      auto& phy = *e.physics;

      if(phy.pos.x <= 0)   { phy.pos.x =   0; phy.vel.x = - phy.vel.x; }
      if(phy.pos.y <= 0)   { phy.pos.y =   0; phy.vel.y = - phy.vel.y; }
      if(phy.pos.x >= 640) { phy.pos.x = 640; phy.vel.x = - phy.vel.x; }
      if(phy.pos.y >= 456) { phy.pos.y = 456; phy.vel.y = - phy.vel.y; }
    }
  }

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------

  void 
  BehaviourChangeVY::run(rod::Entity& e, LevelManager&){

    if(e.physics){
      auto& phy = *e.physics;
      if(counter-- == 0)
      {
        phy.vel.y = - phy.vel.y;
        counter = initial_count;
      }
    }
  };
  
  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------

  void 
  BehaviourShootFreq::run(rod::Entity& e, LevelManager& LevMan){
    if(e.physics){
      auto& phy = *e.physics;
      if(counter-- == 0)
      {
        LevMan.createShot(phy.pos, {4.f, 0});
        counter = initial_count;
      }
    }
  };

  // ---------------------------------------------------------------------
  // ---------------------------------------------------------------------

  void 
  BehaviourAutodestroy::run(rod::Entity& e, LevelManager&){
    if(counter-- == 0) e.markForDestruction();
  };

}
