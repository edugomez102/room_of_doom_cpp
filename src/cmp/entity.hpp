
#pragma once 

#include "render.hpp"
#include "physics.hpp"
#include <optional>
  
namespace rod {

  struct Entity{
    std::optional<RenderComponent>  render{};
    std::optional<PhysicsComponent> physics{};
  };
}
