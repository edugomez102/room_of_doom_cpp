#pragma once 

#include <vector>
#include <uage/macros.h>

namespace uage {

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
