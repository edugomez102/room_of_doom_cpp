#include "keyboard.hpp"

namespace uage {

  bool
  Keyboard::isKeyPressed(KeySym k) const noexcept {
    if (auto it = getIterator(k))
      return (*it)->second;
    return false;
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void 
  Keyboard::keyPressed(KeySym k) noexcept {
    if (auto it = getIterator(k))
      (*it)->second = true;
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  void 
  Keyboard::keyReleased(KeySym k) noexcept {
    if (auto it = getIterator(k))
      (*it)->second = false;
  }

  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  Keyboard::opt_key_it
  Keyboard::getIterator(KeySym k) noexcept {
    auto it = pressed_.find(k);
    if(it != pressed_.end())
      return it;
    return {}; // empty optinal
  }
  
  // --------------------------------------------------------------------------
  // --------------------------------------------------------------------------

  Keyboard::opt_key_it
  Keyboard::getIterator(KeySym k) const noexcept {
    return const_cast<Keyboard*>(this)->getIterator(k);
  }
}
