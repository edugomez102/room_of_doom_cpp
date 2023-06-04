#pragma once 

#include <vector>
#include <uage/macros.h>
#include <cassert>
#include <limits>

namespace uage {

  template <typename ET>
  struct EntityManager {
    explicit EntityManager(std::size_t const num = 0)
    {
      entities_.reserve(num);
    }
    DISABLE_COPY_AND_ASSIGN(EntityManager)

    [[nodiscard]] ET& createEntity() { return new_entities_.emplace_back(); }

    void update(){
      destroy_marked_entities();
      incorporate_new_entities();
    }

    auto begin() { return entities_.begin(); }
    auto end()   { return entities_.end();   }

  private:

    void incorporate_new_entities(){
      for (auto& e : new_entities_) {
        entities_.push_back(std::move(e));
      }
      new_entities_.clear();
    }


    void destroy_marked_entities(){
      assert(entities_.size() < std::numeric_limits<unsigned long>::max());

      for (unsigned long i{entities_.size()}; i != 0; i--) {
        auto& e = entities_[i - 1];

        if (!e.alive){
          // TODO: may fail if entities_.size() very big
          entities_.erase(entities_.begin() + long(i - 1));
        }
      }
    }

    std::vector<ET> entities_{}, new_entities_{};

#ifndef RELEASE
  public:

    ET& getEntity() { return entities_.at(0); }
#endif

  };

}
