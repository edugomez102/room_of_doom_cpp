#include <lib/ut/ut.hpp>

#include <uage/math_types.hpp>
#include <sys/physiscssystem.hpp>
#include <sys/rendersystem.hpp>
#include <types.hpp>

namespace ut = boost::ut;

ut::suite<"Game Systems"> phy_test = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace boost::ut::spec;

  describe("Physiscs system") = [] {

    rod::EntityManager EM{1};
    rod::PhysicsSystem PhySys{};

    auto& e1 = EM.createEntity();
    e1.physics = rod::PhysicsComponent{.pos{0, 0}, .vel{1.f, 0.f}};
    auto& pos = e1.physics->pos;
    auto& vel = e1.physics->vel;

    it("should start at pos 0, 0") = [&] {
      expect(pos.x == 0 && pos.y == 0);
      expect(vel.x == 1.f && vel.y == 0.f);
    };

    it("should be at pos 1, 0 after update") = [&] {
      PhySys.update(EM);
      expect(pos.x == 1 && pos.y == 0);
    };

    it("should return to pos 0, 0") = [&] {
      vel.x = -1.f;
      PhySys.update(EM);
      expect(pos.x == 0 && pos.y == 0);
    };
  };

  describe("Render system") = [] {
    rod::EntityManager EM{1};
    rod::RenderSystem RenSys{4, 4};

    auto& e1 = EM.createEntity();
    e1.render = rod::RenderComponent{.sprite{{1,1}, 0xFFFFFFFF}};

    it("should start at render pos 0, 0") = [&] {
      auto& pos = e1.render->pos;
      expect(pos.x == 0 && pos.y == 0);
    };
  };
};
