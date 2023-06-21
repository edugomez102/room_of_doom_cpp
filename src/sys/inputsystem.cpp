#include "inputsystem.hpp"
#include <iostream>
#include <man/levelman.hpp>
extern "C" {
#include <tinyPTC/tinyptc.h>
}

namespace rod {

  InputSystem::InputSystem() 
  {
    bindKeyboard();
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void 
  InputSystem::update(LevelManager& LevMan) {
    ptc_process_events();
    auto& EM = LevMan.EntMan();

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

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void 
  InputSystem::bindKeyboard()
  {
    ptc_set_on_keypress(onKeypress);
    ptc_set_on_keyrelease(onKeyrelease);
  }

}
