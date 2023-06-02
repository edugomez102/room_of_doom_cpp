#pragma once 

#include <types.hpp>

namespace rod {

  struct LevelManager;

  struct BehaviourSystem {
    void update(LevelManager& EM); 

  private:
    void behaviour_bounce(Entity& e);

  };
}

