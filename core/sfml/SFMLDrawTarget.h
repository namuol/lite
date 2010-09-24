#ifndef _SFMLDRAWTARGET_H_
#define _SFMLDRAWTARGET_H_

#include <list>
using std::list;

#include <SFML/RenderTarget.h>

#include "IDrawTarget.h"

namespace lite
{
    class IDrawable;

    class SFMLDrawTarget : public IDrawTarget
    {
        public:
        static bool compare_draworder(IDrawable* first, IDrawable* second);

        SFMLDrawTarget(RenderTarget* screen);
        virtual void init();
        virtual void deinit();

        virtual void draw(int dt);

        virtual void add_drawable(IDrawable* drawable);
        virtual void rem_drawable(IDrawable* drawable);
        virtual void sort_drawables();

        RenderTarget* screen() const;

        private:
        list<IDrawable *> drawables;

        RenderTarget* _screen;
    };
} // namespace lite
#endif
