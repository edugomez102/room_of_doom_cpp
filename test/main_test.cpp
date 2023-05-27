#include <lib/ut/ut.hpp>

#include <uage/math_types.hpp>

// TOOD: organize etc

int main() {

  using namespace boost::ut;

  "math_types"_test = [] {
    auto d = uage::Dimensions2D{2, 2};
    expect(d.size() == 4);
    d.h = 10;
    expect(d.size() == 0);
  };

}
