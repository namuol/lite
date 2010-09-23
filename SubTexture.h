#ifndef _SUBTEXTURE_H_
#define _SUBTEXTURE_H_

#include <SFML/Graphics.hpp>
using sf::Image;

#include <SFML/Rect.hpp>
using sf::IntRect;

namespace lite
{
    class SubTextureSheet;

    class SubTexture
    {
        public:
        SubTexture(const SubTextureSheet* sheet, int index);

        const SubTextureSheet* sheet() const;
        int index() const;

        const Image* texture() const;
        const IntRect& rectangle() const;

        protected:
        SubTextureSheet* _sheet;
        int _index;
        IntRect _rectangle;
    };

} // namespace lite

#endif
