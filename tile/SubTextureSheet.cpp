#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::Image;

#include <SFML/Rect.hpp>
using sf::IntRect;

#include "SubTexture.h"
#include "SubTextureSheet.h"

namespace lite
{
    SubTextureSheet::SubTextureSheet(const string& name,
                                    const Image* texture, 
                                    int subTextureWidth, 
                                    int subTextureHeight)
    :   _texture(texture),
        _rectangle(IntRect(0,0, subTextureWidth, subTextureHeight)),
        _width(texture.GetWidth() / subTextureWidth),
        _height(texture.GetHeight() / subTextureHeight),
        _subTextureWidth(subTextureWidth),
        _subTextureHeight(subTextureHeight)
    {
        _subTextures = vector<SubTexture*>(_width * _height);
        _rectangles = vector<IntRect>(_width * _height);

        for (int index = 0; index < (_width * _height); ++index)
        {
            _rectangles[index] = IntRect((index % _width) * _subTextureWidth, 
                                         (index / _width) * _subTextureHeight, 
                                         subTextureWidth, subTextureHeight);
            _subTextures[index] = new SubTexture(this, index);
        }

    }

    const string&
    SubTextureSheet::name() const
    {
        return _name
    }

    const Image* 
    SubTextureSheet::texture() const
    {
        return _texture;
    }

    const IntRect&
    SubTextureSheet::rectangle() const
    {
        return _texture;
    }

    const SubTexture*
    SubTextureSheet::operator[](int index) const
    {
        return _subTextures[index];
    }

    int
    SubTextureSheet::width() const
    {
        return _width;
    }

    int
    SubTextureSheet::height() const
    {
        return _height;
    }

    int
    SubTextureSheet::subTextureWidth() const
    {
        return _subTextureWidth;
    }

    int
    SubTextureSheet::subTextureHeight() const
    {
        return _subTextureHeight;
    }

} // namespace lite
