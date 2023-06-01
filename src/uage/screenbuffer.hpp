#pragma once 

#include <cstdint>
#include <vector>
#include "sprite.hpp"
#include "math_types.hpp"

namespace uage {

  struct ScreenBuffer {

    struct ClippedRect {
      Rect2D screen{}, sprite{};
    };

    explicit ScreenBuffer(const uint32_t w, const uint32_t h);

    [[nodiscard]] auto data() noexcept {return data_.data(); };

    [[nodiscard]] Dimensions2D const dim() const noexcept { return dim_; };

    // TODO draw sprite when is not entiriely on screen
    // calculateSpriteClipping()
    ClippedRect calculateSpriteClipping(const Sprite& sprite, const Vec2D& screenPosition);


    // ARGB
    void fill(const uint32_t hexColor);
    void drawSprite(const Sprite& sprite, const Vec2D& position);

    auto begin() { return data_.begin(); }
    auto end()   { return data_.end();   }

  private:
    Dimensions2D const dim_{};
    std::vector<uint32_t> data_{ std::vector<uint32_t>(dim_.size(), 0) };
  };

};
