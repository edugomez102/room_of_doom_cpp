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

    rod::EntityManager EM{2};
    rod::PhysicsSystem PhySys{};

    auto& e_create = EM.createEntity();
    e_create.physics = rod::PhysicsComponent{.pos{0.f, 0.f}, .vel{1.f, 0.f}};

    it("should start at pos 0, 0") = [&] {
      EM.update();

      auto& e = EM.getEntity();
      auto& phy = (*e.physics);

      expect(phy.pos.x == 0.f && phy.pos.y == 0.f);
      expect(phy.vel.x == 1.f && phy.vel.y == 0.f);
    };

    it("should be at pos 1, 0 after update") = [&] {
      EM.update();
      PhySys.update(EM);

      auto& e = EM.getEntity();
      auto& phy = (*e.physics);

      expect(phy.pos.x == 1.f && phy.pos.y == 0.f);
    };

    it("should return to pos 0, 0 after update") = [&] {
      auto& e = EM.getEntity();
      auto& phy = (*e.physics);

      phy.vel.x = -1.f;

      EM.update();
      PhySys.update(EM);

      expect(phy.pos.x == 0.f && phy.pos.y == 0.f);
    };
  };

  // cannot be run in github actions because of graphic enviroment
  // describe("Render system") = [] {
  //   rod::EntityManager EM{1};
  //   rod::RenderSystem RenSys{4, 4};
  //
  //   auto& e1 = EM.createEntity();
  //   e1.render = rod::RenderComponent{.sprite{{1,1}, 0xFFFFFFFF}};
  //
  //   it("should start at render pos 0, 0") = [&] {
  //     auto& pos = e1.render->pos;
  //     expect(pos.x == 0 && pos.y == 0);
  //   };
  // };
};
