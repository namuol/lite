#include "App.h"
#include "IUpdateable.h"

namespace lite
{
    IUpdateable::IUpdateable():
        app(NULL),
        updateorder(0.0f)
    {
    }

    IUpdateable::IUpdateable(App* app):
        app(app),
        updateorder(0.0f)
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
    IUpdateable::get_updateorder() const
    {
        return updateorder;
    }

    void
    IUpdateable::set_updateorder(float updateorder)
    {
        app->sort_updateables();
    }

} // namespace lite
