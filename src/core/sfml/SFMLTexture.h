#ifndef _SFMLTEXTURE_H_
#define _SFMLTEXTURE_H_
#include <SFML/Graphics.hpp>

#include "ITexture.h"

namespace lite
{
    class SFMLTexture : public ITexture
    {
        public:
        SFMLTexture(sf::Image* img):
            ITexture(img->GetWidth(), img->GetHeight()),
            _img(img)
        {
            _sprite = new sf::Sprite(*_img);
        }

        virtual ~SFMLTexture()
        {
            delete _sprite;
        }

        const sf::Image* img() const { return _img; }
        sf::Sprite* sprite() const { return _sprite; }

        protected:
        sf::Image* _img;
        sf::Sprite* _sprite;
    };
} // namespace lite
#endif
