#include "TileMap.h"
#include "Tile.h"

namespace lite {

    TileMap::TileMap(unsigned int width, unsigned int height,
            unsigned int tileWidth, unsigned int tileHeight,
            unsigned int layerCount, unsigned int subLayerCount):
        _tileWidth(tileWidth),
        _tileHeight(tileHeight),
        _layerCount(layerCount),
        _subLayerCount(subLayerCount),
        _tiles(width, vector<Tile*>(height))
    {
    }

    unsigned int
    TileMap::width() const
    {
        return _tiles.size();
    }

    unsigned int
    TileMap::height() const
    {
        return _tiles[0].size();
    }


    unsigned int
    TileMap::tileWidth() const
    {
        return _tileWidth;
    }

    void
    TileMap::tileWidth(unsigned int val)
    {
        _tileWidth = val; 
    }


    unsigned int
    TileMap::tileHeight() const
    {
        return _tileHeight; 
    }

    void
    TileMap::tileHeight(unsigned int val)
    {
        _tileHeight = val;
    }


    unsigned int
    TileMap::layerCount() const
    {
        return _layerCount;
    }

    unsigned int
    TileMap::subLayerCount() const
    {
        return _subLayerCount;
    }


    Tile*
    TileMap::get(int x, int y) const
    {
        if(x < width() && x > 0 &&
           y < height() && y > 0)
        {
            return _tiles[x][y];
        }
        else
        {
            return NULL;
        }
    }


    void
    TileMap::set(int x, int y, const Tile& t)
    {
        Tile* old = _tiles[x][y];
        if(old != NULL)
        {
            delete _tiles[x][y];
        }
        _tiles[x][y] = new Tile(t);
    }

    void
    TileMap::clear(int x, int y)
    {
        Tile* old = _tiles[x][y];
        if(old != NULL)
        {
            delete _tiles[x][y];
        }
        _tiles[x][y] = NULL;
    }

} // namespace lite
