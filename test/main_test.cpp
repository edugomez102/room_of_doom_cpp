#include <lib/ut/ut.hpp>

#include <uage/math_types.hpp>
#include <sys/physiscssystem.hpp>
#include <types.hpp>

int add(int a, int b) {
    return a + b;
}

int main() {

  using namespace boost::ut;

  "addition"_test = [] {
        expect(add(2, 2) == 4_i);
        expect(add(0, 0) == 0_i);
        expect(add(-1, 1) == 0_i);
    };
  
  "math_types"_test = [] {
    auto d = uage::Dimensions2D{2, 2};
    expect(d.size() == 4);
  };

  using namespace boost::ut::literals;
  using namespace boost::ut::spec;

  describe("physiscs system") = [] {

    rod::EntityManager EM{10};
    rod::PhysicsSystem PhySys{};

    auto& e1 = EM.createEntity();
    e1.physics = rod::PhysicsComponent{.pos{0, 0}, .vel{1.f, 0.f}};
    auto& pos = e1.physics->pos;

    it("should be at pos 0, 0") = [&pos] {
      expect(pos.x == 0 && pos.y == 0);
    };

    PhySys.update(EM);

    it("should be at pos 1, 0 after update") = [&pos] {
      expect(pos.x == 1 && pos.y == 0);
    };

    e1.physics->vel.x = -1.f;
    PhySys.update(EM);

    it("should return to pos 0, 0") = [&pos] {
      expect(pos.x == 0 && pos.y == 0);
    };

  };

}
