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


constexpr uint32_t w = 640;
constexpr uint32_t h = 456;

int main()
{
  rod::EntityManager EM{10};
  rod::PhysicsSystem PhySys{};
  rod::RenderSystem  RenSys{w, h};
  rod::PreRenderSystem PreRenSys{};

  auto& e1 = EM.createEntity();
  e1.physics = rod::PhysicsComponent{.pos{10, 10}, .vel{0.f, 1.f}};
  e1.render  = rod::RenderComponent{.sprite{{4, 4}, 0x000000FF}};

  auto& e2 = EM.createEntity();
  e2.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{0, 0}};
  e2.render  = rod::RenderComponent{.sprite{{8, 8}, 0x000000FF}};

  auto& e3 = EM.createEntity();
  e3.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{1.f, 0}};
  e3.render  = rod::RenderComponent{.sprite{{8, 8}, 0x00FF00FF}};

  auto time_now = std::chrono::high_resolution_clock::now;

  auto start      = time_now();
  uint32_t maxfps = 60;
  uint32_t nanosperframe= 1'000'000'000 / maxfps;
  uint32_t frames = 0;

  while( ! ptc_process_events())
  {
    auto frame_start = time_now();

    // TODO: sysman CRTP
    PhySys.update(EM);
    PreRenSys.update(EM);
    RenSys.update(EM);

    while((time_now() - frame_start).count() < nanosperframe );

    ++frames;
  }

  auto end = time_now();

  auto ellapsed = (end - start).count(); //nanoseconds 
  auto ellapsed_secs = double(ellapsed) / 1'000'000'000.0;

  printf("seconds: %f\n", ellapsed_secs);
  printf("frames : %u\n", frames);
  printf("FPS    : %f\n", double(frames) / ellapsed_secs);

  return 0;
}
