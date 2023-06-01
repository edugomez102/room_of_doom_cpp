#include "rendersystem.hpp"
#include <cmath>
#include <cwchar>

namespace rod {

  // --------------------------------------------------------------------------
  // Render
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
  RenderSystem::update(EntityManager& EM) {
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
  PreRenderSystem::update(EntityManager& EM) {
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

