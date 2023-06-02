#include "sprite.hpp"
#include "picoPNG/picopng.hpp"
#include <fstream>
#include <cstring>

namespace uage {

  Sprite::Sprite(Dimensions2D dim, uint32_t color)
    : dim_{dim}
    , data_{std::vector<uint32_t>(dim.size(), color)}
  {
  }

  Sprite::Sprite(const std::filesystem::path& path)
  {
    load_from_file(path);
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  Sprite Sprite::new_subsprite(Rect2D rect) 
  {
    return Sprite{};
  }

  // TODO: wrong color order in array
  void Sprite::load_from_file(std::filesystem::path p)
  {
    std::vector<uint8_t> pixels{};
    unsigned long dw{0}, dh{0};

    auto file = std::ifstream (p, std::ios::binary);

    // open file and add its binary contents to a vector
    std::vector<uint8_t> filevec (
        std::istreambuf_iterator<char>{file},
        std::istreambuf_iterator<char>{}
    );

    decodePNG(pixels, dw, dh, filevec.data(), filevec.size());

    data_.resize(pixels.size() / 4 );
    std::memcpy(data_.data(), pixels.data(), pixels.size());

    dim_.w = uint32_t(dw);
    dim_.h = uint32_t(dh);

  }
}
