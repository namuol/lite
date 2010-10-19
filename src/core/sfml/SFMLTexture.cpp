#include <SFML/Graphics.hpp>

#include "Rect.h"

#include "SFMLTexture.h"

namespace lite
{
    SFMLTexture::SFMLTexture(sf::Image* img):
        ITexture(img->GetWidth(), img->GetHeight()),
        _img(img)
    {
        _sprite = new sf::Sprite(*_img);
    }
    
    ITexture*
    SFMLTexture::sub_texture(const IntRect& rect) const
    {
        const SFMLTexture* root;
        IntRect final_rect;
        if( this->root() )
        {
            root = dynamic_cast<const SFMLTexture*>(this->root());
            final_rect = IntRect(this->rect().x + rect.x, this->rect().y + rect.y,
                            rect.width, rect.height);
        }
        else
        {
            root = this;
            final_rect = rect;
        }

        return new SFMLTexture(root, final_rect);
    }

    SFMLTexture::~SFMLTexture()
    {
        delete _sprite;
    }

    sf::Image*
    SFMLTexture::img() const
    {
        return _img;
    }

    sf::Sprite*
    SFMLTexture::sprite() const
    {
        return _sprite;
    }
    
    // Protected:
    SFMLTexture::SFMLTexture(const SFMLTexture* root, const IntRect& rect):
        ITexture(root, rect),
        _img(root->img())
    {
        _sprite = new sf::Sprite(*_img);
    }

} // namespace lite
