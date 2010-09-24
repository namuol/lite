// TODO: DOCUMENTATION
// An interface for a surface to draw on.

#ifndef _IDRAWTARGET_H_
#define _IDRAWTARGET_H_
namespace lite
{
    class IDrawable;

    class IDrawTarget
    {
        public:
        virtual void init() = 0;
        virtual void deinit() = 0;

        virtual void draw(int dt) = 0;

        virtual void add_drawable(IDrawable* drawable) = 0;
        virtual void rem_drawable(IDrawable* drawable) = 0;
        virtual void sort_drawables() = 0;
    };
} // namespace lite
#endif
