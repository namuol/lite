#include "IDrawable.h"
#include "IDrawTarget.h"

namespace lite
{
    bool
    compare_draworder(IDrawable* first, IDrawable* second)
    {
        return first->drawOrder() < second->drawOrder();
    }

    IDrawTarget::IDrawTarget(unsigned int width, unsigned int height):
        _width(width),
        _height(height)
    {
    }

    void
    IDrawTarget::add_drawable(IDrawable* drawable)
    {
        drawables.push_back(drawable); 
        drawables.sort(compare_draworder);
    }

    void
    IDrawTarget::rem_drawable(IDrawable* drawable)
    {
        drawables.remove(drawable);
    }

    void
    IDrawTarget::sort_drawables()
    {
        drawables.sort(compare_draworder);
    }

    void
    IDrawTarget::draw(int dt)
    {
        for( list<IDrawable *>::iterator d = drawables.begin(); d != drawables.end(); ++d ) {
            (*d)->draw(dt);
        }
    }
} // namespace lite
