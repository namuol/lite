//#define _MOUSE_DEBUG
#ifdef _MOUSE_DEBUG
#include <iostream>
using namespace std;
#endif

#include "Vector2.h"

#include "ITimer.h"
#include "Mouse.h"

namespace fix
{
    Mouse::Mouse()
    {
    }

    const Vector2& Mouse::position() const
    {
        return _position;
    }

    void Mouse::position(const Vector2& value)
    {
        // TODO: This is dangerous-ish.. make it so that the _prev_position always
        //        corresponds to what the previous position was in the last frame.
        _prev_position = _position;
        _position = value;
        #ifdef _MOUSE_DEBUG
        cout << "mouse pos changed: x=" << _position.x << " y=" << _position.y << endl;
        #endif
    }

    Vector2 Mouse::motion() const
    {
        return _position - _prev_position;
    }

} // namespace fix
