#include <iostream>
extern "C" {
#include <tinyPTC/tinyptc.h>
}

#include <cstdint>
#include <optional>
#include <cmath>
#include <chrono>

#include <cmp/render.hpp>
#include <cmp/physics.hpp>
#include <man/entityman.hpp>
#include <man/levelman.hpp>

#include <types.hpp>

#include <sys/physiscssystem.hpp>
#include <sys/rendersystem.hpp>
#include <sys/behavioursystem.hpp>
#include <sys/inputsystem.hpp>

#include <man/systemman.hpp>

#include <uage/clock.hpp>

int main()
{
  rod::LevelManager LevMan{};
  auto& EM = LevMan.EntMan();

  auto SM = rod::SystemManager<
    rod::InputSystem,
    rod::BehaviourSystem,
    rod::PhysicsSystem,
    rod::PreRenderSystem,
    rod::RenderSystem
  >{};

  LevMan.startTestLevel();

  uage::Clock clock;

  while( ! ptc_process_events())
  {
    clock.new_frame();

    SM.update(LevMan);
    EM.update();

    while(clock.is_waiting());
    clock.update_frames();
  }

  clock.print_status();

  return 0;
}
