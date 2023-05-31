#pragma once  

#include <X11/X.h>
#include <X11/keysym.h>
#include <uage/macros.h>

#include <unordered_map>
#include <optional>

namespace uage {

  struct Keyboard {
    using storage_type = std::unordered_map<KeySym, bool>;
    using opt_key_it   = std::optional<storage_type::iterator>;

    explicit Keyboard() = default;

    Keyboard(const Keyboard&)           = delete;
    Keyboard(Keyboard&&)                = delete;
    Keyboard operator=(const Keyboard&) = delete;
    Keyboard operator=(Keyboard&&)      = delete;
    
    [[nodiscard]] bool isKeyPressed(KeySym k) const noexcept;

    void keyPressed(KeySym k)  noexcept;
    void keyReleased(KeySym k) noexcept;

  private:

    opt_key_it getIterator(KeySym k) noexcept;
    opt_key_it getIterator(KeySym k) const noexcept;

    std::unordered_map<KeySym, bool> pressed_ {
        { XK_BackSpace , false},
        { XK_Tab       , false},
        { XK_Clear     , false},
        { XK_Return    , false},
        { XK_Pause     , false},
        { XK_Escape    , false},
        { XK_space     , false},
        { XK_Page_Up   , false},
        { XK_Page_Down , false},
        { XK_End       , false},
        { XK_Home      , false},
        { XK_Left      , false},
        { XK_Up        , false},
        { XK_Right     , false},
        { XK_Down      , false},
        { XK_Insert    , false},
        { XK_Delete    , false},
        { XK_0         , false},
        { XK_1         , false},
        { XK_2         , false},
        { XK_3         , false},
        { XK_4         , false},
        { XK_5         , false},
        { XK_6         , false},
        { XK_7         , false},
        { XK_8         , false},
        { XK_9         , false},
        { XK_a         , false},
        { XK_b         , false},
        { XK_c         , false},
        { XK_d         , false},
        { XK_e         , false},
        { XK_f         , false},
        { XK_g         , false},
        { XK_h         , false},
        { XK_i         , false},
        { XK_j         , false},
        { XK_k         , false},
        { XK_l         , false},
        { XK_m         , false},
        { XK_n         , false},
        { XK_o         , false},
        { XK_p         , false},
        { XK_q         , false},
        { XK_r         , false},
        { XK_s         , false},
        { XK_t         , false},
        { XK_u         , false},
        { XK_v         , false},
        { XK_w         , false},
        { XK_x         , false},
        { XK_y         , false},
        { XK_z         , false},
        { XK_A         , false}, // Capital A
        { XK_B         , false}, // Capital B
        { XK_C         , false}, // Capital C
        { XK_D         , false}, // Capital D
        { XK_E         , false}, // Capital E
        { XK_F         , false}, // Capital F
        { XK_G         , false}, // Capital G
        { XK_H         , false}, // Capital H
        { XK_I         , false}, // Capital I
        { XK_J         , false}, // Capital J
        { XK_K         , false}, // Capital K
        { XK_L         , false}, // Capital L
        { XK_M         , false}, // Capital M
        { XK_N         , false}, // Capital N
        { XK_O         , false}, // Capital O
        { XK_P         , false}, // Capital P
        { XK_Q         , false}, // Capital Q
        { XK_R         , false}, // Capital R
        { XK_S         , false}, // Capital S
        { XK_T         , false}, // Capital T
        { XK_U         , false}, // Capital U
        { XK_V         , false}, // Capital V
        { XK_W         , false}, // Capital W
        { XK_X         , false}, // Capital X
        { XK_Y         , false}, // Capital Y
        { XK_Z         , false}, // Capital Z
        { XK_F1        , false},
        { XK_F2        , false},
        { XK_F3        , false},
        { XK_F4        , false},
        { XK_F5        , false},
        { XK_F6        , false},
        { XK_F7        , false},
        { XK_F8        , false},
        { XK_F9        , false},
        { XK_F10       , false},
        { XK_F11       , false},
        { XK_F12       , false}
    };

  };
}
