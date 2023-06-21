#pragma once

#include <types.hpp>

namespace rod {

  template <typename ...Args>
  struct SystemManager{

    SystemManager() = default;

    void update(LevelManager& LevMan) {

      std::apply([&LevMan](auto&... sys)
      {
        ((sys.update(LevMan)), ...);
      }, systems_);
    }

  private:
    std::tuple<Args...> systems_{};
  };

}
