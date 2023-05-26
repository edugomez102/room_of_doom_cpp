extern "C" {
#include "tinyPTC/tinyptc.h"
}
#include "uage/sprite.hpp"
#include "uage/screenbuffer.hpp"
#include <cstdint>
#include <optional>

#define DISABLE_COPY_AND_ASSIGN(Class) \
Class(const Class&)            = delete; \
Class(Class&&)                 = delete; \
Class& operator=(const Class&) = delete; \
Class& operator=(Class&&)      = delete;

constexpr uint32_t w = 640;
constexpr uint32_t h = 456;

// components

namespace rod {

  struct RenderComponent {
    uage::Sprite sprite{};
  };

  struct PhysicsComponent {
    uage::Vec2D pos{};
    uage::Vec2D vel{};
  };

  struct Entity{
    std::optional<RenderComponent>  render{};
    std::optional<PhysicsComponent> physics{};
  };
}


namespace uage {

// manageers

  template <typename ET>
  struct EntityManager {
    explicit EntityManager(std::size_t const num = 0)
    {
      entities_.reserve(num);
    }
    DISABLE_COPY_AND_ASSIGN(EntityManager)

    [[nodiscard]] ET& createEntity() { return entities_.emplace_back(); }

    auto begin() { return entities_.begin(); }
    auto end()   { return entities_.end();   }

  private:
    std::vector<ET> entities_{};

  };

}

namespace rod {

  using EntityManager = uage::EntityManager<rod::Entity>;

// systems
  struct PhysicsSystem {

    void update(EntityManager& EM) {
      for (Entity& e : EM) {
        if(e.physics) {
          e.physics->pos += e.physics->vel;
        }
      }
    }
  };

  struct RenderSystem {
    explicit RenderSystem(const uint32_t w, const uint32_t h)
      : screen_{w, h}
    {
      ptc_open("window", w, h);
    }

    ~RenderSystem() {
      ptc_close();
    }
    DISABLE_COPY_AND_ASSIGN(RenderSystem)

    void update(EntityManager& EM) {
      screen_.fill(0);
      for (Entity& e : EM) {
        if(e.render && e.physics){
          screen_.drawSprite(e.render->sprite, e.physics->pos);
        }
      }
      ptc_update(screen_.data());
    }

  private:
    uage::ScreenBuffer screen_{0, 0};
    
  };
}


int main()
{
  rod::EntityManager EM{10};
  rod::PhysicsSystem PhySys{};
  rod::RenderSystem  RenSys{w, h};

  auto& e1 = EM.createEntity();
  e1.physics = rod::PhysicsComponent{.pos{10, 10}, .vel{0, 1}};
  e1.render  = rod::RenderComponent{.sprite{{4, 4}, 0x000000FF}};

  auto& e2 = EM.createEntity();
  e2.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{0, 0}};
  e2.render  = rod::RenderComponent{.sprite{{8, 8}, 0x000000FF}};

  auto& e3 = EM.createEntity();
  e3.physics = rod::PhysicsComponent{.pos{20, 40}, .vel{1, 0}};
  e3.render  = rod::RenderComponent{.sprite{{8, 8}, 0x00FF00FF}};

  while( ! ptc_process_events())
  {
    PhySys.update(EM);
    RenSys.update(EM);
  }

  return 0;
}
