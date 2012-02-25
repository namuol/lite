#ifndef _COLOR_H_
#define _COLOR_H_

#include "types.h"
namespace lite
{
    class Color
    {
        public:
        Color();
        Color(const Color& other);
        Color(u8 r, u8 g, u8 b, u8 a=255);
        Color(int r, int g, int b, int a=1.f);
        Color(float r, float g, float b, float a=1.f);

        static const Color WHITE;
        static const Color BLACK;
        static const Color CLEAR;

        // TODO: Operators
        u8 r, g, b, a;
    };
} // namespace lite
#endif
