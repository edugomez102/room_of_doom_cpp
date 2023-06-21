#include "rendersystem.hpp"
#include <cmath>
#include <man/levelman.hpp>

namespace rod {

  // --------------------------------------------------------------------------
  // Render
  // --------------------------------------------------------------------------

  RenderSystem::RenderSystem()
    : screen_{d_w, d_h}
  {
    ptc_open("window", int(d_w), int(d_h));
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  RenderSystem::RenderSystem(const uint32_t w, const uint32_t h)
    : screen_{w, h}
  {
    ptc_open("window", int(w), int(h));
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  RenderSystem::~RenderSystem() {
    ptc_close();
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void 
  RenderSystem::update(LevelManager& LevMan) {
    auto& EM = LevMan.EntMan();
    screen_.fill(0);
    for (Entity& e : EM) {
      if(e.render){
        screen_.drawSprite(e.render->sprite, e.render->pos);
      }
    }
    ptc_update(screen_.data());
  }

  // --------------------------------------------------------------------------
  // PreRender
  // --------------------------------------------------------------------------

  void
  PreRenderSystem::update(LevelManager& LevMan) {
    auto& EM = LevMan.EntMan();
    for (Entity& e : EM) {
      if(e.physics && e.render) {
        auto &phy = (*e.physics).pos;
        auto &ren = (*e.render).pos;

        ren.x = int32_t(std::round(phy.x));
        ren.y = int32_t(std::round(phy.y));
      }
    }
  }

}

