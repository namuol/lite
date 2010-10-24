#include <string>
using std::string;

#include <SFML/Graphics.hpp>

#include "IDrawable.h"
#include "IDrawTarget.h"

#include "SFMLTexture.h"

#include "SFMLDrawTarget.h"

namespace lite
{
    SFMLDrawTarget::SFMLDrawTarget(unsigned int width, unsigned int height,
                                    const string& title):
        IDrawTarget(width, height)
    {
        _window = new sf::RenderWindow(sf::VideoMode(_width,_height), title);
    }

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
                                float rotation,
                                const Color& rgba,
                                Blend::Mode mode)
    {
        // To render a texture with SFML, I'm currently just creating
        //  a dummy sf::Sprite that uses the SFMLTexture we want to render
        //  and then using the sf::Window.Draw function to render the sprite
        //  after applying position, scale, rotation, and blend mode parameters.
        //
        // This is a very inefficient way to render a texture.
        // Perhaps I could copy/paste code from sf::Sprite's Render
        //  function instead.
        // Another idea might be to ditch SFML's built in rendering methods and
        //  write a "spritebatch"-like class that uses vertex buffers and texture
        //  atlases for optimal efficiency. This idea might be best-suited for a 
        //  total rewrite using SDL and OpenGL, as it would require a lot of 
        //  "low-level" OpenGL code.

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

        sprite->SetColor(sf::Color(rgba.r,rgba.g,rgba.b,rgba.a));
        sprite->SetBlendMode(sfMode);
        sprite->SetPosition(x, y);
        sprite->SetScale(scalex, scaley);
        sprite->Rotate(rotation);
        _window->Draw(*sprite);
        sprite->Rotate(-rotation);
    }
} // namespace lite
