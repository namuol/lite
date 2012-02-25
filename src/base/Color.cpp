#include "types.h"
#include "util.h"
#include "Color.h"

namespace lite
{

    Color::Color():
        r(0), g(0), b(0), a(255)
    {
    }

    Color::Color(const Color& other):
        r(other.r),
        g(other.g),
        b(other.b),
        a(other.a)
    {
    }


    Color::Color(u8 r, u8 g, u8 b, u8 a):
        r(r), g(g), b(b), a(a)
    {
    }

    Color::Color(int r, int g, int b, int a):
        r((u8)CLAMP(0,255,r)),
        g((u8)CLAMP(0,255,g)),
        b((u8)CLAMP(0,255,b)),
        a((u8)CLAMP(0,255,a))
    {
    }

    Color::Color(float r, float g, float b, float a)
    {
        // I use round<u32> rather than round<u8>  in case of overflow.
        this->r = CLAMP(0, 255, (round<float,u32>(r*255)));
        this->g = CLAMP(0, 255, (round<float,u32>(g*255)));
        this->b = CLAMP(0, 255, (round<float,u32>(b*255)));
        this->a = CLAMP(0, 255, (round<float,u32>(a*255)));
    }

    const Color Color::WHITE = Color(255,255,255,255);
    const Color Color::BLACK = Color(0,0,0,255);
    const Color Color::CLEAR = Color(0,0,0,0);
} // namespace lite
