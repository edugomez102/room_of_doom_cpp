#pragma once 

#include <types.hpp>

namespace rod {

  // struct EntityManager;
  // struct Entity;

  struct BehaviourSystem {
    void update(EntityManager& EM); 

  private:
    void behaviour_bounce(Entity& e);
  };

}

