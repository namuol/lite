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
        SFMLTexture(sf::Image* img);
        
        virtual ITexture* sub_texture(const IntRect& rect) const;
        
        virtual ~SFMLTexture();

        sf::Image* img() const;
        sf::Sprite* sprite() const;

        protected:
        SFMLTexture(const SFMLTexture* root, const IntRect& rect);

        sf::Image* _img;
        sf::Sprite* _sprite;
    };
} // namespace lite
#endif
