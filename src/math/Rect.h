#ifndef _RECT_H_
#define _RECT_H_

#include "Vector2.h"

namespace lite
{
    template<typename T>
    class Rect
    {
        public:
        Rect<T>():
            x(0), y(0),
            width(1),height(1)
        {
        }

        Rect<T>(T _x, T _y, T _width, T _height):
            x(_x), y(_y),
            width(_width),height(_height)
        {
        }

        Rect<T>(const Rect<T>& other):
            x(other.x), y(other.y),
            width(other.width), height(other.height)
        {
        }

        inline T left() const { return x; }
        inline T top() const { return y; }
        inline T right() const { return x + width; }
        inline T bottom() const { return y + height; }

        inline bool contains(const Vector2& point) const
        {
            return  point.x > x &&
                    point.x < (x + width) &&
                    point.y > y &&
                    point.y < (y + height);
        }

        inline bool contains(const Rect<T>& rect) const
        {
            return  contains(Vector2(rect.x,rect.y)) &&
                    contains(Vector2(rect.right(),rect.bottom()));
        }

        inline bool intersects(const Rect<T>& other) const
        {
            return  !(bottom() < other.top() ||
                      top() > other.bottom() ||
                      right() < other.left() ||
                      left() > other.right);
        }

        inline bool operator<(const Rect<T>& other) const
        {
            return (other.x < x ||
                    other.y < y);
        }

        T x, y;
        T width, height;
    };

    typedef Rect<int> IntRect;
    typedef Rect<float> FloatRect;

} // namespace lite
#endif
