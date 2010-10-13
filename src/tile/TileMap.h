#ifndef _TILEMAP_H_
#define _TILEMAP_H_

#include <vector>
using std::vector;

namespace lite
{
    class Tile;

    class TileMap
    {
        public:
        TileMap(unsigned int width, unsigned int height,
                unsigned int tileWidth, unsigned int tileHeight,
                unsigned int layerCount, unsigned int subLayerCount);

        unsigned int width() const;
        unsigned int height() const;

        unsigned int tileWidth() const;
        void tileWidth(unsigned int val);

        unsigned int tileHeight() const;
        void tileHeight(unsigned int val);

        unsigned int layerCount() const;
        unsigned int subLayerCount() const;

        Tile* get(int x, int y) const;

        void set(int x, int y, const Tile& t);
        void clear(int x, int y);

        protected:
        unsigned int _tileWidth, _tileHeight;

        unsigned int _layerCount, _subLayerCount;

        vector<vector<Tile*> > _tiles;
    };


} // namespace lite

#endif
