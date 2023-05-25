#pragma once 

#include "math_types.hpp"
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <filesystem>

namespace uage {

  struct Sprite{

    Sprite(Dimensions2D dim, uint32_t color);

    // TODO
    // Sprite& load_from_file(std::filesystem::path p);
    // Sprite new_subsprite(Rect2D const& rect);

    Dimensions2D const dim() const { return dim_; }
    auto data() const { return data_.data(); }

    private:
      Dimensions2D dim_{};
      std::vector<uint32_t> data_ { std::vector<uint32_t>(100, 0) };

  };
}
