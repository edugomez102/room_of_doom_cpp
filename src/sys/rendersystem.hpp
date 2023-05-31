#pragma once 

extern "C" {
#include "tinyPTC/tinyptc.h"
}
#include <uage/macros.h>
#include <uage/screenbuffer.hpp>
#include <types.hpp>

namespace rod {

  struct PreRenderSystem{
    void update(EntityManager& EM);
  };

  struct RenderSystem {

    explicit RenderSystem(const uint32_t w, const uint32_t h);

    ~RenderSystem();

    DISABLE_COPY_AND_ASSIGN(RenderSystem)

    void update(EntityManager& EM);

  private:
    uage::ScreenBuffer screen_{0, 0};

  };
}
