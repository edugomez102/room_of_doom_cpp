#include <lib/ut/ut.hpp>
#include <uage/keyboard.hpp>

namespace ut = boost::ut;

ut::suite<"uage::Keyboard"> keyboard_test = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::spec;

  auto kb = uage::Keyboard{};
  it("should have key W pressed") = [&] {
    kb.keyPressed(XK_w);
    expect(kb.isKeyPressed(XK_w));
  };

  it("should no longer have key W pressed") = [&] {
    kb.keyReleased(XK_w);
    expect(!kb.isKeyPressed(XK_w));
  };

};
