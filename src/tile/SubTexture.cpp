#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::Image;

#include <SFML/Rect.hpp>
using sf::IntRect;

#include "SubTextureSheet.h"
#include "SubTexture.h"

namespace lite
{

    SubTexture::SubTexture(const SubTextureSheet* sheet, int index):
        _sheet(sheet),
        _index(index),
        _rectangle(_sheet->rectangles[_index])
    {
    }

    const SubTextureSheet*
    SubTexture::sheet() const
    {
        return _sheet;
    }

    int
    index() const
    {
        return _index;
    }

    const Image*
    SubTexture::texture() const
    {
        return _sheet->_texture;
    }

    const IntRect&
    SubTexture::rectangle() const
    {
        return _rectangle;
    }

} // namespace lite
