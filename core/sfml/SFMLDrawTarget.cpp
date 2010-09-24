#include "IDrawable.h"
#include "SFMLDrawTarget.h"

namespace lite
{
    bool
    SFMLDrawTarget::compare_draworder(IDrawable* first, IDrawable* second)
    {
        return first->draworder() < second->draworder();
    }


    SFMLDrawTarget::SFMLDrawTarget(RenderTarget* screen):
    _screen(screen)
    {
    }

    void
    SFMLDrawTarget::init()
    {
        // TODO
    }

    void
    SFMLDrawTarget::deinit()
    {
        // TODO
    }

    void
    SFMLDrawTarget::add_drawable(IDrawable* drawable)
    {
        drawables.push_back(drawable); 
        drawables.sort(compare_draworder);
    }

    void
    SFMLDrawTarget::rem_drawable(IDrawable* drawable)
    {
        drawables.remove(drawable);
    }

    void
    SFMLDrawTarget::sort_drawables()
    {
        drawables.sort(compare_draworder);
    }

    void
    SFMLDrawTarget::draw(int dt)
    {
        // TODO
        for( list<IDrawable *>::iterator d = drawables.begin(); d != drawables.end(); ++d ) {
            (*d)->draw(dt);
        }
    }

    RenderTarget*
    SFMLDrawTarget::screen() const
    {
        return screen;
    }

} // namespace lite
