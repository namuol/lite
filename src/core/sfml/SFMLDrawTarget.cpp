#include <SFML/Graphics.hpp>

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
                                float rotation, Blend::Mode mode)
    {
        // This isn't the most efficient way to render a texture...
        // Perhaps I could copy/paste code from sf::Sprite's Render
        //  function instead.
        const SFMLTexture* sftex = dynamic_cast<const SFMLTexture*>(tex);
        sf::Sprite* sprite = sftex->sprite();
        sprite->SetSubRect(sf::IntRect(
            tex->rect().x,
            tex->rect().y,
            tex->rect().x + tex->rect().width,
            tex->rect().y + tex->rect().height
        ));

        sf::Blend::Mode sfMode;
        switch(mode)
        {
        case Blend::ALPHA: sfMode = sf::Blend::Alpha; break;
        case Blend::ADD: sfMode = sf::Blend::Add; break;
        case Blend::MULT: sfMode = sf::Blend::Multiply; break;
        case Blend::NONE: sfMode = sf::Blend::None; break;
        default: sfMode = sf::Blend::Alpha;
        }

        sprite->SetBlendMode(sfMode);
        sprite->SetPosition(x, y);
        sprite->SetScale(scalex, scaley);
        sprite->Rotate(rotation);
        _window->Draw(*sprite);
        sprite->Rotate(-rotation);
    }
} // namespace lite
