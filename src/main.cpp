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

#include <types.hpp>

#include <sys/physiscssystem.hpp>
#include <sys/rendersystem.hpp>

#include <uage/clock.hpp>

constexpr uint32_t w = 640;
constexpr uint32_t h = 456;

int main()
{
  rod::EntityManager EM{10};
  rod::PhysicsSystem PhySys{};
  rod::RenderSystem  RenSys{w, h};
  rod::PreRenderSystem PreRenSys{};

  uage::Clock clock;

  auto& e1 = EM.createEntity();
  e1.physics = rod::PhysicsComponent{.pos{10, 10}, .vel{0.f, 1.f}};
  e1.render  = rod::RenderComponent{.sprite{{4, 4}, 0x000000FF}};

  auto& e2 = EM.createEntity();
  e2.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{0, 0}};
  e2.render  = rod::RenderComponent{.sprite{{8, 8}, 0x000000FF}};

  auto& e3 = EM.createEntity();
  e3.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{1.f, 0}};
  e3.render  = rod::RenderComponent{.sprite{{8, 8}, 0x00FF00FF}};

  while( ! ptc_process_events())
  {
    clock.new_frame();

    // TODO: sysman CRTP
    PhySys.update(EM);
    PreRenSys.update(EM);
    RenSys.update(EM);

    while(clock.is_waiting());
    clock.update_frames();
  }

  clock.print_status();

  return 0;
}
