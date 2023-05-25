#pragma once  

#include <X11/X.h>
#include <X11/keysym.h>

#include <unordered_map>
#include <optional>

namespace uage {

  struct Keyboard {
    using storage_type = std::unordered_map<KeySym, bool>;
    using optKeyIter   = std::optional<storage_type::iterator>;

    explicit Keyboard() = default;

    Keyboard(const Keyboard&)           = delete;
    Keyboard(Keyboard&&)                = delete;
    Keyboard operator=(const Keyboard&) = delete;
    Keyboard operator=(Keyboard&&)      = delete;
    

    [[nodiscard]] bool isKeyPressed(KeySym k) noexcept;

    void keyPressed(KeySym k)  noexcept;
    void keyReleased(KeySym k) noexcept;

  private:

    // storage_type
    // TODO


  };

}
