// TODO: DOCUMENTATION
// NOTE: This class is quite meaningless without an InputManager to go along with it.
// An arbitrary number of buttons can be associated with a mouse. These need not be
//  actual mouse buttons (they could be keys)...

#ifndef _MOUSE_H_
#define _MOUSE_H_
#include "Vector2.h"

namespace fix
{
    class Mouse
    {
        public:
        Mouse();
        
        const Vector2& position() const;
        void position(const Vector2& value);

        Vector2 motion() const;

        private:
        Vector2 _position;
        Vector2 _prev_position;
    };
}
#endif
