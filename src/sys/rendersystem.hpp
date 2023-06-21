#pragma once 

extern "C" {
#include <tinyPTC/tinyptc.h>
}
#include <uage/macros.h>
#include <uage/screenbuffer.hpp>
#include <types.hpp>

namespace rod {

  struct PreRenderSystem{
    void update(LevelManager& EM);
  };

  struct RenderSystem {

    explicit RenderSystem(const uint32_t w, const uint32_t h);

    RenderSystem();

    ~RenderSystem();

    DISABLE_COPY_AND_ASSIGN(RenderSystem)

    void update(LevelManager& EM);

  private:
    uage::ScreenBuffer screen_{0, 0};

    inline static constexpr uint32_t d_w = 640;
    inline static constexpr uint32_t d_h = 456;
  };
}
