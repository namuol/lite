#include "IDrawable.h"
#include "IDrawTarget.h"
#include "SFMLDrawTarget.h"

namespace lite
{
    SFMLDrawTarget::SFMLDrawTarget(RenderWindow* window):
    _window(window)
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
    SFMLDrawTarget::draw(int dt)
    {
        _window->Clear();
        IDrawTarget::draw(dt);
        _window->Display();
    }
} // namespace lite
