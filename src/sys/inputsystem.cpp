#include "inputsystem.hpp"
extern "C" {
#include <tinyPTC/tinyptc.h>
}

namespace rod {

  InputSystem::InputSystem() 
  {
    ptc_set_on_keypress(onKeypress);
    ptc_set_on_keyrelease(onKeyrelease);
  }

  void 
  InputSystem::update(EntityManager& EM) const {
    ptc_process_events();

    for (auto& e : EM) {
      if(e.input && e.physics){
        auto& inp = *(e.input);
        auto& phy = *(e.physics);

        phy.vel = {0.f, 0.f};
        if     (kb_.isKeyPressed(inp.left))  phy.vel.x -= inp.impulse;
        else if(kb_.isKeyPressed(inp.right)) phy.vel.x += inp.impulse;
        if     (kb_.isKeyPressed(inp.up))    phy.vel.y -= inp.impulse;
        else if(kb_.isKeyPressed(inp.down))  phy.vel.y += inp.impulse;
      }
    }
  }
}
