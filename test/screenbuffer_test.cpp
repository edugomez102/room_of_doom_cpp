#include <lib/ut/ut.hpp>

#include <uage/screenbuffer.hpp>

namespace ut = boost::ut;

ut::suite<"screen buffer"> screenbuf = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace boost::ut::spec;

  auto screen = uage::ScreenBuffer{10, 10};

  "dim"_test = [&] {
    expect(screen.dim().size() == 100);
  };

};
