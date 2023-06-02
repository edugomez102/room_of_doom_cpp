#pragma once  

#include <cstdint>
#include <memory>

namespace rod {
  struct Entity;
  struct LevelManager;

  struct Behaviour{
    virtual void run(rod::Entity& e, LevelManager& LevMan) = 0;
    virtual ~Behaviour() = default;
  };

  struct BehaviourBounce: Behaviour{
    void run(rod::Entity& e, LevelManager& LevMan) final;
  };

  struct BehaviourChangeVY: Behaviour{
    explicit BehaviourChangeVY(const uint32_t ic)
      :initial_count{ic} {}

    void run(rod::Entity& e, LevelManager& LevMan) final; 

    uint32_t initial_count{60};
    uint32_t counter{initial_count};

  };

  struct BehaviourShootFreq: Behaviour{
    explicit BehaviourShootFreq(const uint32_t ic)
      :initial_count{ic} {}
    void run(rod::Entity& e, LevelManager& LevMan) final; 

    uint32_t initial_count{60};
    uint32_t counter{initial_count};

  };

  struct BehaviourAutodestroy: Behaviour{
    explicit BehaviourAutodestroy(const uint32_t c)
      :counter{c} {}
    void run(rod::Entity& e, LevelManager& LevMan) final; 

    uint32_t counter{60};

  };

  struct BehaviourComponent{
    std::unique_ptr<Behaviour> behaviour{};
  };
}

