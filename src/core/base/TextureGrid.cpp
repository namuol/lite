#include <map>
using std::map;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include "ITexture.h"
#include "Rect.h"

#include "TextureGrid.h"

namespace lite
{
    TextureGrid::TextureGrid():
        _tex(NULL),
        _width(0),
        _height(0),
        _sub_width(0),
        _sub_height(0)
    {
    }

    TextureGrid::TextureGrid(const ITexture* tex,
                unsigned int sub_width,
                unsigned int sub_height):
        _tex(tex),
        _width(tex->width() / sub_width),
        _height(tex->height() / sub_height),
        _sub_width(sub_width),
        _sub_height(sub_height)
    {
        /*
        cout << "gw: " << _width << endl;
        cout << "gh: " << _height << endl;
        */

        _grid_map = vector<const ITexture*>(_width * _height);
        for (int index = 0; index < (_width * _height); ++index)
        {
            IntRect rect = IntRect((index % _width) * _sub_width, 
                                    (index / _width) * _sub_height,
                                    _sub_width, _sub_height);
            const ITexture* subtex = _tex->sub_texture(rect);
            _grid_map[index] = subtex;

            /* TODO: Debug message system
            if(subtex == NULL)
            {
                cout << "TEXTUREGRID NULL! " << index << ": "
                     << "  x:" << rect.x << " y:"<<rect.y<<" w:"
                     << rect.width << " h:" << rect.height << endl << endl;
            }
            */
        }
    }

    const ITexture*
    TextureGrid::operator[](unsigned int index) const
    {
        if(index >= _grid_map.size())
        {
            return NULL;
        }

        return _grid_map[index];

    }

    unsigned int
    TextureGrid::size() const
    {
        return _width * _height;
    }

    unsigned int
    TextureGrid::width() const
    {
        return _width;
    }

    unsigned int
    TextureGrid::height() const
    {
        return _height;
    }

    unsigned int
    TextureGrid::sub_width() const
    {
        return _sub_width;
    }

    unsigned int
    TextureGrid::sub_height() const
    {
        return _sub_height;
    }

    const ITexture*
    TextureGrid::tex() const
    {
        return _tex;
    }

} // namespace lite
