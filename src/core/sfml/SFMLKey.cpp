#include <SFML/Window/Event.hpp>
using namespace sf::Key;

#include "Key.h"
#include "SFMLKey.h"

#define KMAP(code, key) case code: return key

namespace lite
{
    Key
    keyFromCode(Code c)
    {
        switch(c)
        {
            KMAP(A,K_a);
            KMAP(B,K_b);
            KMAP(C,K_c);
            KMAP(D,K_d);
            KMAP(E,K_e);
            KMAP(F,K_f);
            KMAP(G,K_g);
            KMAP(H,K_h);
            KMAP(I,K_i);
            KMAP(J,K_j);
            KMAP(K,K_k);
            KMAP(L,K_l);
            KMAP(M,K_m);
            KMAP(N,K_n);
            KMAP(O,K_o);
            KMAP(P,K_p);
            KMAP(Q,K_q);
            KMAP(R,K_r);
            KMAP(S,K_s);
            KMAP(T,K_t);
            KMAP(U,K_u);
            KMAP(V,K_v);
            KMAP(W,K_w);
            KMAP(X,K_x);
            KMAP(Y,K_y);
            KMAP(Z,K_z);

            KMAP(Num0,K_0);
            KMAP(Num1,K_1);
            KMAP(Num2,K_2);
            KMAP(Num3,K_3);
            KMAP(Num4,K_4);
            KMAP(Num5,K_5);
            KMAP(Num6,K_6);
            KMAP(Num7,K_7);
            KMAP(Num8,K_8);
            KMAP(Num9,K_9);

            KMAP(Escape,K_ESCAPE);

            KMAP(LControl,K_LCTRL);
            KMAP(LShift,K_LSHIFT);
            KMAP(LAlt,K_LALT);
            KMAP(LSystem,K_LSUPER);

            KMAP(RControl,K_RCTRL);
            KMAP(RShift,K_RSHIFT);
            KMAP(RAlt,K_RALT);
            KMAP(RSystem,K_RSUPER);

            KMAP(Menu,K_MENU);
            KMAP(LBracket,K_LEFTBRACKET);
            KMAP(RBracket,K_RIGHTBRACKET);
            KMAP(SemiColon,K_SEMICOLON);
            KMAP(Comma,K_COMMA);
            KMAP(Period,K_PERIOD);
            KMAP(Quote,K_QUOTE);
            KMAP(Slash,K_SLASH);
            KMAP(BackSlash,K_BACKSLASH);
            // Tilde???
            KMAP(Equal,K_EQUALS);
            // Dash??? Perhaps Minus?
            KMAP(Space,K_SPACE);
            KMAP(Return,K_RETURN);
            KMAP(Back, K_BACKSPACE);
            KMAP(Tab, K_TAB);
            KMAP(PageUp,K_PAGEUP);
            KMAP(PageDown,K_PAGEDOWN);
            KMAP(End,K_END);
            KMAP(Home,K_HOME);
            KMAP(Insert,K_INSERT);
            KMAP(Delete,K_DELETE);

            KMAP(Add,K_KP_PLUS);
            KMAP(Subtract,K_KP_MINUS);
            KMAP(Multiply,K_KP_MULTIPLY);
            KMAP(Divide,K_KP_DIVIDE);

            KMAP(Left,K_LEFT);
            KMAP(Right,K_RIGHT);
            KMAP(Down,K_DOWN);
            KMAP(Up,K_UP);

            KMAP(Numpad0,K_KP0);
            KMAP(Numpad1,K_KP1);
            KMAP(Numpad2,K_KP2);
            KMAP(Numpad3,K_KP3);
            KMAP(Numpad4,K_KP4);
            KMAP(Numpad5,K_KP5);
            KMAP(Numpad6,K_KP6);
            KMAP(Numpad7,K_KP7);
            KMAP(Numpad8,K_KP8);
            KMAP(Numpad9,K_KP9);

            KMAP(F1,K_F1);
            KMAP(F2,K_F2);
            KMAP(F3,K_F3);
            KMAP(F4,K_F4);
            KMAP(F5,K_F5);
            KMAP(F6,K_F6);
            KMAP(F7,K_F7);
            KMAP(F8,K_F8);
            KMAP(F9,K_F9);
            KMAP(F10,K_F10);
            KMAP(F11,K_F11);
            KMAP(F12,K_F12);
            KMAP(F13,K_F13);
            KMAP(F14,K_F14);
            KMAP(F15,K_F15);

            KMAP(Pause,K_PAUSE);

            /* Missing: Many of these would appear with modifiers
             *   (but this is poor design on behalf of SFML, as
             *    people could use keymaps that have such keys without
             *    modifiers, or with alternate modifiers...)
            KMAP(Exclaim,K_EXCLAIM);
            KMAP(Quotedbl,K_QUOTEDBL);
            KMAP(Hash,K_HASH);
            KMAP(Dollar,K_DOLLAR);
            KMAP(Ampersand,K_AMPERSAND);
            KMAP(Leftparen,K_LEFTPAREN);
            KMAP(Rightparen,K_RIGHTPAREN);

            KMAP(Colon,K_COLON);
            KMAP(Less,K_LESS);
            KMAP(Greater,K_GREATER);
            KMAP(Question,K_QUESTION);
            KMAP(At,K_AT);
            KMAP(Caret,K_CARET);
            KMAP(Underscore,K_UNDERSCORE);
            KMAP(Backquote,K_BACKQUOTE);

            KMAP(Numlock,K_NUMLOCK);
            KMAP(Capslock,K_CAPSLOCK);
            KMAP(Scrollock,K_SCROLLOCK);
            KMAP(Mode,K_MODE);
            KMAP(Help,K_HELP);
            KMAP(Print,K_PRINT);
            KMAP(Sysreq,K_SYSREQ);
            KMAP(Break,K_BREAK);
            KMAP(Power,K_POWER);
            KMAP(Euro,K_EURO);
            */

            /* Where do these belong?
            KMAP(Add,K_PLUS);
            KMAP(Subtract,K_MINUS);
            KMAP(Multiply,K_ASTERISK);
            KMAP(Divide,K_SLASH); // Might not work?
            */

            /* Missing:
            KMAP(Numpad_period,K_KP_PERIOD);
            KMAP(Numpad_enter,K_KP_ENTER);
            KMAP(Numpad_equals,K_KP_EQUALS);
            */

            // Missing:
            //K_CLEAR,                          //clear

            default:
                return K_NULL;
        }
    }

} // namespace lite
