#include "IDrawable.h"
#include "IDrawTarget.h"

namespace lite
{
    bool
    compare_draworder(IDrawable* first, IDrawable* second)
    {
        return first->drawOrder() < second->drawOrder();
    }
    
    IDrawTarget::IDrawTarget():
        _width(0),
        _height(0),
        _clearColor(),
        _filterMode(Filter::NEAREST)
    {
    }

    IDrawTarget::~IDrawTarget()
    {
    }

    IDrawTarget::IDrawTarget(unsigned int width, unsigned int height,
                             const Color& clearColor):
        _width(width),
        _height(height),
        _clearColor(clearColor),
        _filterMode(Filter::NEAREST)
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
        this->clear();
        for( list<IDrawable *>::iterator d = drawables.begin(); d != drawables.end(); ++d ) {
            if((*d)->visible())
                (*d)->draw(dt);
        }
    }

    unsigned int
    IDrawTarget::width() const
    {
        return _width;
    }

    unsigned int
    IDrawTarget::height() const
    {
        return _height;
    }

    void
    IDrawTarget::filterMode(Filter::Mode filterMode) {
        _filterMode = filterMode;
        _filterModeChanged();
    }

    Filter::Mode
    IDrawTarget::filterMode() const {
        return _filterMode;
    }

    void 
    IDrawTarget::clearColor(const Color& val)
    {
        _clearColor = val;
    }

    const Color&
    IDrawTarget::clearColor() const
    {
        return _clearColor;
    }

} // namespace lite
