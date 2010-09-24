#include "IDrawable.h"
#include "SFMLDrawTarget.h"

namespace lite
{
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

    RenderTarget*
    SFMLDrawTarget::screen() const
    {
        return screen;
    }

} // namespace lite
