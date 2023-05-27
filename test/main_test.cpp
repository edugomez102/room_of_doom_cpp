#include "ut.hpp"

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


}
