#pragma once  

#include <cstdint>
#include <memory>

namespace rod {
  struct Entity;

  struct Behaviour{
    virtual void run(rod::Entity& e) = 0;
  };

  struct BehaviourBounce: Behaviour{
    void run(rod::Entity& e) final;
  };

  struct BehaviourChangeVY: Behaviour{
    void run(rod::Entity& e) final; 

    uint32_t initial_count{60};
    uint32_t counter{initial_count};

  };

  struct BehaviourComponent{
    std::unique_ptr<Behaviour> behaviour{nullptr};
  };
}

