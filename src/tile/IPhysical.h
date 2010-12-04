#ifndef _IPHYSICAL_H_
#define _IPHYSICAL_H_

namespace lite
{
    public class IPhysical
    {
        const Vector2& position() const = 0;
        void position(const Vector2& val) = 0;

        const Vector2& velocity() const = 0;
        void velocity(const Vector2& val) = 0;

        const Vector2& netForce() const = 0;
        void netForce(const Vector2& val) = 0;

        float mass() const = 0;
        void mass(float val) = 0;
    }
} // namespace lite

#endif
