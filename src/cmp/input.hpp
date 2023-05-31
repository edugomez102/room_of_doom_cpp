#pragma once 

#include <X11/X.h>
#include <X11/keysym.h>


namespace rod {

  struct InputComponent{

    KeySym left  {XK_a};
    KeySym right {XK_d};
    KeySym up    {XK_w};
    KeySym down  {XK_s};

    float impulse {2.0f};
  };
};

