#include "behavioursystem.hpp"
#include <man/levelman.hpp>

namespace rod {

  void BehaviourSystem::update(LevelManager &LevMan)
  {
    auto& EM = LevMan.EntMan();

    for (auto& e : EM) {
      if (e.beh_cmp) {
        auto& behcmp = *e.beh_cmp;
        if(behcmp.behaviour) {
          behcmp.behaviour->run(e, LevMan);
        }
      }
    }
  }


}

