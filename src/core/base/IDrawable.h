// TODO: DOCUMENTATION
// An interface for anything in the game that can be rendered.

#include "IDrawTarget.h"

#ifndef _IDRAWABLE_H_
#define _IDRAWABLE_H_
namespace lite
{
    class IDrawTarget;

    class IDrawable
    {
        public:
        IDrawable(IDrawTarget* target, float drawOrder=0.f);
        virtual ~IDrawable();

        virtual float drawOrder() const;
        virtual void drawOrder(float drawOrder);
        
        virtual bool visible() const;
        virtual void visible(bool val);

        virtual void draw(int dt) const = 0;

        protected:
        IDrawTarget* drawTarget;
        float _drawOrder;
        bool _visible;
    };
} // namespace lite
#endif
