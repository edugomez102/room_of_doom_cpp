#include "uage/sprite.hpp"
#include <ut/ut.hpp>

#include <uage/screenbuffer.hpp>

namespace ut = boost::ut;

ut::suite<"uage::ScreenBuffer"> screenbuf = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace boost::ut::spec;

  "screen dim"_test = [&] {
    auto screen = uage::ScreenBuffer{4, 4};
    expect(screen.dim().size() == 16);
  };

  constexpr auto screen_fill = 0xFFFFFFFF;
  constexpr auto sp_color    = 0xFFAAAAAA;

  it("should fill the screen") = [&] {
    auto screen = uage::ScreenBuffer{2, 2};
    screen.fill(screen_fill);
    bool wrong = false;
    for (auto i : screen) {
      if (i != screen_fill) wrong = true;
    }
    expect(!wrong);
  };

  //   | | |
  //   | | |
  describe("2x2 screenbuffer") = [&] {
    auto screen = uage::ScreenBuffer{2, 2};
    screen.fill(screen_fill);

    //   |x|x|
    //   | | |
    it("should paint a sprite of 2x1 in 0,0") = [&] {
      auto sp = uage::Sprite{{2,1}, sp_color};
      screen.drawSprite(sp, {0, 0});

      expect(screen.data()[0] == sp_color
          && screen.data()[1] == sp_color
          && screen.data()[2] == screen_fill
          && screen.data()[3] == screen_fill);
    };
    screen.fill(0);

    it("should paint nothing") = [&] {
      auto sp = uage::Sprite{};
      screen.drawSprite(sp, {0, 0});

      expect(screen.data()[0] == 0
          && screen.data()[1] == 0
          && screen.data()[2] == 0
          && screen.data()[3] == 0);
    };

    //   |x|x|
    //   |x|x|
    it("should paint a sprite of 2x2 in 0,0") = [&] {
      auto sp = uage::Sprite{{2,2}, sp_color};
      screen.drawSprite(sp, {0, 0});

      expect(screen.data()[0] == sp_color
          && screen.data()[1] == sp_color
          && screen.data()[2] == sp_color
          && screen.data()[3] == sp_color);
    };
  };

  //   | | | | |
  //   | | | | |
  //   | | | | |
  //   | | | | |
  describe("4x4 screenbuffer") = [] {
    auto screen = uage::ScreenBuffer{4, 4};

    //   | | | | |
    //   | |x| | |
    //   | |x| | |
    //   | | | | |
    it("should paint a sprite of 1x2 in 1,1") = [&] {
      auto sp = uage::Sprite{{1,2}, sp_color};
      screen.drawSprite(sp, {1, 1});
      expect(screen.data()[1*4 + 1] == sp_color 
          && screen.data()[2*4 + 1] == sp_color);
    };
  };

};
