#include "App.h"
#include "IDrawTarget.h"
#include "IDrawable.h"

namespace lite
{
    IDrawable::IDrawable(IDrawTarget* drawTarget, float drawOrder):
        drawTarget(drawTarget),
        _drawOrder(drawOrder),
        _visible(true)
    {
    }

    IDrawable::~IDrawable()
    {
        drawTarget->rem_drawable(this);
    }
    
    float
    IDrawable::drawOrder() const
    {
        return _drawOrder;
    }
    
    void
    IDrawable::drawOrder(float drawOrder)
    {
        _drawOrder = drawOrder;
        drawTarget->sort_drawables();
    }

    bool
    IDrawable::visible() const
    {
        return _visible;
    }

    void
    IDrawable::visible(bool val)
    {
        _visible = val;
    }

} // namespace lite
