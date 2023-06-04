
#include <ut/ut.hpp>
#include <uage/clock.hpp>

namespace ut = boost::ut;

ut::suite<"uage::Clock"> clock_test = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("clock") = [] {

    uage::Clock clock{};

    it("should be waiting after a new frame") = [&] {
      clock.new_frame();
      expect(clock.is_waiting());
    };

    it("should have count 60 frames") = [&] {

      for (int i = 0; i < 60; i++) {
        clock.update_frames();
      }
      expect(clock.frames() == 60);
    };

  };




};
