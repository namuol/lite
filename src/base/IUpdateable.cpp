#include "App.h"
#include "IUpdateable.h"

namespace lite
{
    IUpdateable::IUpdateable():
        app(NULL),
        _updateOrder(0.0f)
    {
    }

    IUpdateable::IUpdateable(App* app):
        app(app),
        _updateOrder(0.0f)
    {
    }

    IUpdateable::~IUpdateable()
    {
        if(app)
        {
            app->rem_updateable(this);
        }
    }

    float
    IUpdateable::updateOrder() const
    {
        return _updateOrder;
    }

    void
    IUpdateable::updateOrder(float val)
    {
        _updateOrder = val;
        app->sort_updateables();
    }

} // namespace lite
