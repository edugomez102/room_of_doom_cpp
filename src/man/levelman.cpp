#include "levelman.hpp"

  constexpr uint32_t sphex[4 * 4] = {
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
    0x00FF0000, 0x0000FF00, 0x000000FF, 0x00FF0000,
  };

namespace rod {

  LevelManager::LevelManager(size_t storage, SpriteManager spriteman)
    : EM_{storage}, SprM_{spriteman}
  {}

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void LevelManager::createShot(const uage::Vec2Df pos, const uage::Vec2Df vel){
    auto& e_shot = EM_.createEntity();
    e_shot.physics = rod::PhysicsComponent{.pos{pos}, .vel{vel}};
    e_shot.render  = rod::RenderComponent{.sprite{{8, 8}, 0x00FFFFFF}};
    e_shot.beh_cmp = rod::BehaviourComponent{
      std::make_unique<rod::BehaviourAutodestroy>(60)
    };
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void LevelManager::startTestLevel()
  {
    auto& EM = EM_;

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
    e2.input = rod::InputComponent{.impulse = 4};
    // auto s = uage::Sprite{"assets/img/sprite_sheet_01.png"};
    // auto s = uage::Sprite{{4, 4}, 0x00FFFF00};
    // e2.render  = rod::RenderComponent{.sprite{s}};
    // auto s = uage::Sprite{"assets/img/sprite_sheet_01.png"};

    // e2.render  = rod::RenderComponent{uage::Sprite{"assets/img/sprite_sheet_01.png"}};

    // auto sub = s.new_subsprite({{32,16},{16,16}});
    // auto sub = s.new_subsprite({{0,0},{16,32}});
    auto sub = SprM_.createSprite(SpriteType::Player);
    e2.render  = rod::RenderComponent{sub};

  }
}
