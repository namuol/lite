// TODO: DOCUMENTATION
// An interface for a surface to draw on.

#ifndef _IDRAWTARGET_H_
#define _IDRAWTARGET_H_
#include <list>
using std::list;

#include "ITexture.h"

namespace lite
{
    class IDrawable;

    bool compare_draworder(IDrawable* first, IDrawable* second);

    class IDrawTarget
    {
        public:
        IDrawTarget(unsigned int width, unsigned int height);

        virtual void init() = 0;
        virtual void deinit() = 0;

        // I really would prefer that this be pure-virtual, but I cannot call
        //  drawTexture in the base Sprite class otherwise.
        virtual void drawTexture(const ITexture* tex, float x=0.f, float y=0.f,
                                 float scalex=1.f, float scaley=1.f,
                                 float rotation=0.f) = 0;

        virtual void draw(int dt);

        virtual void add_drawable(IDrawable* drawable);
        virtual void rem_drawable(IDrawable* drawable);
        virtual void sort_drawables();

        protected:
        list<IDrawable*> drawables;
        unsigned int _width, _height;
    };
} // namespace lite
#endif
