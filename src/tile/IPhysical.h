#ifndef _IPHYSICAL_H_
#define _IPHYSICAL_H_

#include "Vector2.h"

namespace lite
{
    class IPhysical
    {
        virtual const Vector2& position() const = 0;
        virtual void position(const Vector2& val) = 0;

        virtual const Vector2& velocity() const = 0;
        virtual void velocity(const Vector2& val) = 0;

        virtual const Vector2& netForce() const = 0;
        virtual void netForce(const Vector2& val) = 0;

        virtual float mass() const = 0;
        virtual void mass(float val) = 0;

        virtual float maxSpeed() const = 0;
        virtual void maxSpeed(float val) = 0;

        void applyPhysics();
    };
} // namespace lite

#endif
