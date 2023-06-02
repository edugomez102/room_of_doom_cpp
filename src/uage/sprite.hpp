#pragma once 

#include "math_types.hpp"
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <filesystem>

namespace uage {

  struct Sprite{

    Sprite() = default;
    Sprite(Dimensions2D dim, uint32_t color);
    Sprite(const std::filesystem::path& path);

    void load_from_file(std::filesystem::path p);

    Sprite new_subsprite(Rect2D rect);

    Dimensions2D const dim() const { return dim_; }
    auto data() const { return data_.data(); }

    auto begin() { return data_.begin(); }
    auto end()   { return data_.end(); }

    private:

      Dimensions2D dim_{};
      std::vector<uint32_t> data_ { std::vector<uint32_t>(100, 0) };

      /**
       * @brief 
       * Our renderer renders colors as ARGB but PNG files store the bitmap in 
       * RGBA format so it is needed to swap the array values in order to get the
       * right colors of the loaded file
       *
       * @param pixels vector with RGBA bitmap
       */
      void swap_RGBA_to_ARGB(std::vector<uint8_t>& pixels);

  };
}
