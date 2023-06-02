#include "levelman.hpp"

namespace rod {

  void LevelManager::createShot(const uage::Vec2Df pos, const uage::Vec2Df vel){
    auto& e_shot = EM_.createEntity();
    e_shot.physics = rod::PhysicsComponent{.pos{pos}, .vel{vel}};
    e_shot.render  = rod::RenderComponent{.sprite{{8, 8}, 0x00FFFFFF}};
    e_shot.beh_cmp = rod::BehaviourComponent{
      std::make_unique<rod::BehaviourAutodestroy>(60)
    };
  }
}
