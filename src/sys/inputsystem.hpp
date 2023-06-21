#pragma once 

#include <types.hpp>
#include <uage/keyboard.hpp>

namespace rod {

  struct InputSystem{
    InputSystem();

    void update(LevelManager& LevMan);

  private:

    inline static uage::Keyboard kb_{};

    // using tinyptc, this should be called after window init
    static void bindKeyboard();

    static void onKeypress(KeySym k)   { kb_.keyPressed(k);  }
    static void onKeyrelease(KeySym k) { kb_.keyReleased(k); }

  };
}
