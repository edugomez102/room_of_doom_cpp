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

#include <uage/clock.hpp>

constexpr uint32_t w = 640;
constexpr uint32_t h = 456;

int main()
{
  rod::LevelManager LevMan{};
  rod::PhysicsSystem PhySys{};
  rod::RenderSystem  RenSys{w, h};
  rod::PreRenderSystem PreRenSys{};
  rod::BehaviourSystem BehSys{};
  rod::InputSystem InpSys{};

  auto& EM = LevMan.EntMan();

  LevMan.startTestLevel();

  uage::Clock clock;

  while( ! ptc_process_events())
  {
    clock.new_frame();

    // TODO: sysman CRTP
    PreRenSys.update(EM);
    RenSys.update(EM);

    InpSys.update(EM);
    BehSys.update(LevMan);
    PhySys.update(EM);

    EM.update();

    while(clock.is_waiting());
    clock.update_frames();
  }

  clock.print_status();

  return 0;
}
