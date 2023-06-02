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

  uage::Clock clock;

  auto& e1 = EM.createEntity();
  e1.physics = rod::PhysicsComponent{.pos{32, 24}, .vel{0.f, 0.f}};
  e1.render  = rod::RenderComponent{.sprite{{16, 8}, 0x000000FF}};
  e1.beh_cmp = rod::BehaviourComponent{
    .behaviour{std::make_unique<rod::BehaviourShootFreq>(60)
  }};

  // auto& e3 = EM.createEntity();
  // e3.physics = rod::PhysicsComponent{.pos{9, 40}, .vel{2.f, 0.f}};
  // e3.render  = rod::RenderComponent{.sprite{{16, 8}, 0x0000AAFF}};
  // e3.beh_cmp = rod::BehaviourComponent{
  //   .behaviour{std::make_unique<rod::BehaviourBounce>()
  // }};

  auto& e2 = EM.createEntity();
  e2.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{0, 0}};
  e2.input = rod::InputComponent{.impulse = 8};
  auto s = uage::Sprite{};
  s.load_from_file("assets/img/sprite_sheet_01.png");
  e2.render  = rod::RenderComponent{.sprite{s}};

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
