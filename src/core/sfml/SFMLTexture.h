#ifndef _SFMLTEXTURE_H_
#define _SFMLTEXTURE_H_
#include <SFML/Graphics.hpp>

#include "ITexture.h"
#include "Rect.h"
using lite::IntRect;

namespace lite
{
    class SFMLTexture : public ITexture
    {
        public:
        SFMLTexture(const sf::Image* img):
            ITexture(img->GetWidth(), img->GetHeight()),
            _img(img)
        {
            _sprite = new sf::Sprite(*_img);
        }
        
        virtual ITexture* sub_texture(const IntRect& rect) const
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

        virtual ~SFMLTexture()
        {
            delete _sprite;
        }

        const sf::Image* img() const { return _img; }
        sf::Sprite* sprite() const { return _sprite; }

        protected:
        SFMLTexture(const SFMLTexture* root, const IntRect& rect):
            ITexture(root, rect),
            _img(root->img())
        {
            _sprite = new sf::Sprite(*_img);
        }

        const sf::Image* _img;
        sf::Sprite* _sprite;
    };
} // namespace lite
#endif
