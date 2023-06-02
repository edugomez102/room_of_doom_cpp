
#pragma once 

#include "render.hpp"
#include "physics.hpp"
#include "behaviour.hpp"
#include "input.hpp"

#include <optional>
  
namespace rod {

  struct Entity{
    std::optional<RenderComponent>    render{};
    std::optional<PhysicsComponent>   physics{};
    std::optional<BehaviourComponent> beh_cmp{};
    std::optional<InputComponent>     input{};

    void markForDestruction() { alive = false; }

    bool alive{true};
  };
}
