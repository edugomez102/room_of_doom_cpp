#include "uage/sprite.hpp"
#include <lib/ut/ut.hpp>

#include <uage/screenbuffer.hpp>

namespace ut = boost::ut;

ut::suite<"uage::ScreenBuffer"> screenbuf = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace boost::ut::spec;

  auto screen = uage::ScreenBuffer{4, 4};

  "screen dim"_test = [&] {
    expect(screen.dim().size() == 16);
  };

  const auto screen_fill = 0xFFFFFFFF;
  it("should have first elements painted") = [&] {
    screen.fill(screen_fill);
    expect(screen.data()[0] == screen_fill);
    expect(screen.data()[1] == screen_fill);
  };

  const auto sp_color = 0xFFAAAAAA;

  //   |x|x| | |
  //   | | | | |
  //   | | | | |
  //   | | | | |
  it("should paint a sprite of 2x1 in 0,0") = [&] {
    auto sp = uage::Sprite{{2,1}, sp_color};
    screen.drawSprite(sp, {0, 0});
    expect(screen.data()[0] == sp_color);
    expect(screen.data()[1] == sp_color);
    expect(screen.data()[2] == screen_fill);
  };

  //   | | | | |
  //   | |x| | |
  //   | |x| | |
  //   | | | | |
  it("should paint a sprite of 1x2 in 1,1") = [&] {
    auto sp = uage::Sprite{{1,2}, sp_color};
    screen.drawSprite(sp, {1, 1});
    expect(screen.data()[1*4 + 0] == screen_fill);
    expect(screen.data()[1*4 + 1] == sp_color);
    expect(screen.data()[1*4 + 2] == screen_fill);
    expect(screen.data()[2*4 + 1] == sp_color);
  };

};
