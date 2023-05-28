#include "behavioursystem.hpp"

namespace rod {

  void BehaviourSystem::update(EntityManager &EM)
  {
    for (auto& e : EM) {
      if (e.beh_cmp) {
        auto& behcmp = *e.beh_cmp;
        if(behcmp.behaviour) {
          behcmp.behaviour->run(e);
        }
      }
    }
  }


}

