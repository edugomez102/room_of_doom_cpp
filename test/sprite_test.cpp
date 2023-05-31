#include <lib/ut/ut.hpp>
#include <uage/sprite.hpp>

namespace ut = boost::ut;

ut::suite<"uage::Sprite"> sprite_test = [] 
{
  using namespace boost::ut;
  using namespace boost::ut::spec;

  describe("image loads") = [] {
    it("should load a 16x16 image") = [] {
      auto s = uage::Sprite{};
      auto pre_data = s.data();
      s.load_from_file("assets/img/image1.png"); // 16 16
      expect(s.dim().h == 16 && s.dim().w == 16);
      expect(s.dim().size() == 16 * 16);
      expect(pre_data != s.data());

    };
    
    it("should load a 16x20 image") = [] {
      auto s = uage::Sprite{};
      s.load_from_file("assets/img/image3.png"); // 16 20
      expect(s.dim().h == 16 && s.dim().w == 20);
      expect(s.dim().size() == 16 * 20);
    };

    it("should not change data if path does not exist") = [] {
      auto s = uage::Sprite{};
      auto pre_data = s.data();
      s.load_from_file("assets/img/image_null.png"); 
      expect(pre_data == s.data());
    };
  };

  it("should fill data with given hex color") = [] {
    auto dim = uage::Dimensions2D{4, 4};
    uint32_t hex = 0x00FF00FF;
    auto s = uage::Sprite{dim, hex};
    auto data = s.data();
    bool bad_fill = false;
    for (uint32_t i = 0; i < dim.size(); i++) {
      if (data[i] != hex) bad_fill = true;
    }
    expect(!bad_fill);
  };
};
