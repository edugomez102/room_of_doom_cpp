#pragma once 

#include <types.hpp>
#include <uage/keyboard.hpp>

namespace rod {

  struct InputSystem{
    explicit InputSystem();

    void update(EntityManager& EM) const;

    private:

    inline static uage::Keyboard kb_{};

    static void onKeypress(KeySym k)   { kb_.keyPressed(k);  }
    static void onKeyrelease(KeySym k) { kb_.keyReleased(k); }

  };
}
