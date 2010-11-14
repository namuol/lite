#ifndef _TEXTUREGRID_H_
#define _TEXTUREGRID_H_

#include <map>
using std::map;

#include <vector>
using std::vector;

namespace lite
{
    class ITexture;

    class TextureGrid
    {
        public:

        TextureGrid();

        TextureGrid(const ITexture* tex,
                    unsigned int sub_width,
                    unsigned int sub_height);

        const ITexture* operator[](unsigned int index);

        unsigned int size() const;
        unsigned int width() const;
        unsigned int height() const;

        private:
        const ITexture* _tex;
        unsigned int _width, _height;
        unsigned int _sub_width, _sub_height;
        vector<const ITexture*> _grid_map;
    };
} // namespace lite

#endif
