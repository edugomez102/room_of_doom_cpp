#include "sprite.hpp"
#include "picoPNG/picopng.hpp"
#include <fstream>
#include <cstring>

namespace uage {

  Sprite::Sprite(Dimensions2D dim, uint32_t color)
    : dim_{dim}
    , data_{std::vector<uint32_t>(dim.size(), color)}
  {}

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  Sprite::Sprite(const std::filesystem::path& path)
  {
    load_from_file(path);
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  Sprite Sprite::new_subsprite(Rect2D rect) 
  {
    // TODO control if out of sprite
    Sprite subsprite = Sprite{rect.dim, 0};

    const uint32_t* p_sprite = data_.data() + rect.pos.x + (uint32_t(rect.pos.y) * dim_.w);
    uint32_t* p_subsprite = subsprite.data_.data();

    for (uint32_t i = 0; i < subsprite.dim_.h; ++i) {
      std::copy(
        p_sprite,
        p_sprite + subsprite.dim_.w,
        p_subsprite
      );
      p_subsprite += subsprite.dim_.w;
      p_sprite += dim_.w;
    }

    return subsprite;
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

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
    swap_RGBA_to_ARGB(pixels);

    std::memcpy(data_.data(), pixels.data(), pixels.size());

    dim_.w = uint32_t(dw);
    dim_.h = uint32_t(dh);

  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void Sprite::swap_RGBA_to_ARGB(std::vector<uint8_t>& pixels)
  {
    for (size_t i = 0; i < pixels.size(); i += 4) {
      uint8_t temp = pixels[i];        // Store red channel temporarily
      pixels[i] = pixels[i + 2];       // Assign blue channel to red channel position
      pixels[i + 2] = temp;            // Assign stored red channel to blue channel position
    }
  }
}
