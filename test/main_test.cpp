#include "ut.hpp"
#include "uage/sprite.hpp"

int add(int a, int b) {
    uage::Sprite{{1,1}, 0x00000000};
    return a + b;
}

int main() {

  using namespace boost::ut;

  "addition"_test = [] {
        expect(add(2, 2) == 4_i);
        expect(add(0, 0) == 0_i);
        expect(add(-1, 1) == 0_i);
        expect(add(-1, 6) == 0_i);
    };
}
