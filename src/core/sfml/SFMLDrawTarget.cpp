#include "IDrawable.h"
#include "IDrawTarget.h"

#include "SFMLTexture.h"

#include "SFMLDrawTarget.h"

namespace lite
{
    SFMLDrawTarget::SFMLDrawTarget(RenderWindow* window):
        IDrawTarget(window->GetWidth(), window->GetHeight()),
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

    void
    SFMLDrawTarget::drawTexture(const ITexture* tex, float x, float y,
                                float scalex, float scaley,
                                float rotation)
    {
        // This isn't the most efficient way to render a texture...
        // Perhaps I could copy/paste code from sf::Sprite's Render
        //  function instead.
        const SFMLTexture* sftex = dynamic_cast<const SFMLTexture*>(tex);
        sf::Sprite* sprite = sftex->sprite();
        sprite->SetPosition(x, y);
        sprite->SetScale(scalex, scaley);
        sprite->Rotate(rotation);
        _window->Draw(*sprite);
    }
} // namespace lite
