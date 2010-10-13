#ifndef _TEXTURESHEET_H_
#define _TEXTURESHEET_H_

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "ITexture.h"
#include "Rect.h"

#include <iostream>
using std::cout;
using std::endl;

namespace lite
{
    class TextureSheet
    {
        public:
        TextureSheet():
            _tex(NULL)
        {
        }

        TextureSheet(const ITexture* tex):
            _tex(tex)
        {
        }

        const ITexture* operator[](const IntRect& subrect)
        {
            if( _subtextures.find(subrect) == _subtextures.end() )
            {
                create(subrect);
            }
            return _subtextures[subrect];
        }

        protected:
        const ITexture* create(const IntRect& subrect)
        {
            const ITexture* subtex = _tex->sub_texture(subrect);
            _subtextures[subrect] = subtex;
            return _subtextures[subrect];
        }

        const ITexture* _tex;
        map<IntRect, const ITexture*> _subtextures;
    };

    class TextureGrid
    {
        public:

        TextureGrid():
            _tex(NULL),
            _width(0),
            _height(0),
            _sub_width(0),
            _sub_height(0)
        {
        }

        TextureGrid(const ITexture* tex,
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

        const ITexture* operator[](unsigned int index)
        {
            if(index >= _grid_map.size())
            {
                return NULL;
            }

            return _grid_map[index];

        }

        unsigned int size() const
        {
            return _width * _height;
        }

        unsigned int width() const
        {
            return _width;
        }

        unsigned int height() const
        {
            return _height;
        }

        private:
        const ITexture* _tex;
        unsigned int _width, _height;
        unsigned int _sub_width, _sub_height;
        vector<const ITexture*> _grid_map;
    };
} // namespace lite
#endif
