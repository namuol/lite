// TODO: DOCUMENTATION
// An interface for a surface to draw on.

#ifndef _IDRAWTARGET_H_
#define _IDRAWTARGET_H_
#include <list>
using std::list;

namespace lite
{
    class IDrawable;

    bool compare_draworder(IDrawable* first, IDrawable* second);

    class IDrawTarget
    {
        public:
        virtual void init() = 0;
        virtual void deinit() = 0;

        virtual void draw(int dt);

        virtual void add_drawable(IDrawable* drawable);
        virtual void rem_drawable(IDrawable* drawable);
        virtual void sort_drawables();

        protected:
        list<IDrawable*> drawables;
    };
} // namespace lite
#endif
