#include <iostream>
using namespace std;

#include "EdgeMap.h"
#include "ITileMap.h"
#include "Tile.h"

namespace lite {
    EdgeMap::EdgeMap(const ITileMap* tileMap,
        const ITexture* topTex,
        const ITexture* leftTex,
        const ITexture* bottomTex,
        const ITexture* rightTex
    ):
        _tileMap(tileMap),
        _topTex(topTex),
        _leftTex(leftTex),
        _bottomTex(bottomTex),
        _rightTex(rightTex),
        _edgeTiles(16) // 2^4 different edge combinations.
    {
        for(unsigned int i=0; i<_edgeTiles.size(); ++i)
        {
            vector<vector<const ITexture*> > textures(1, vector<const ITexture*>(4));
            textures[0][0] = i & 1 ? _topTex : NULL;
            textures[0][1] = i & 2 ? _leftTex : NULL;
            textures[0][2] = i & 4 ? _bottomTex : NULL;
            textures[0][3] = i & 8 ? _rightTex : NULL;
            _edgeTiles[i] = new Tile(textures);
        }
    }

    EdgeMap::~EdgeMap()
    {
        for(unsigned int i=0; i<_edgeTiles.size(); ++i)
        {
            delete _edgeTiles[i];
            _edgeTiles[i] = NULL;
        }
    }

    unsigned int
    EdgeMap::width() const
    {
        return _tileMap->width();
    }

    unsigned int
    EdgeMap::height() const
    {
        return _tileMap->height();
    }


    unsigned int
    EdgeMap::tileWidth() const
    {
        return _tileMap->tileWidth();
    }

    void
    EdgeMap::tileWidth(unsigned int val)
    {
        // DOES NOTHING!
    }


    unsigned int
    EdgeMap::tileHeight() const
    {
        return _tileMap->tileHeight(); 
    }

    void
    EdgeMap::tileHeight(unsigned int val)
    {
        // DOES NOTHING!
    }


    unsigned int
    EdgeMap::layerCount() const
    {
        return 1;
    }

    unsigned int
    EdgeMap::subLayerCount() const
    {
        return 4;
    }


    Tile*
    EdgeMap::get(int x, int y) const
    {
        if(x < (int)width() && x >= 0 &&
           y < (int)height() && y >= 0)
        {
            Tile* tile = _tileMap->get(x,y);
            if(tile == NULL ||
               !tile->isSolid())
            {
                return NULL;
            }
            
            EdgeArray edges = tile->edges();
            int edgesInt = (
                (edges[TOP] == SOLID) |
                (edges[LEFT] == SOLID) << 1 |
                (edges[BOTTOM] == SOLID) << 2 |
                (edges[RIGHT] == SOLID) << 3
            );

            return _edgeTiles[edgesInt];
        }
        else
        {
            return NULL;
        }
    }


    void
    EdgeMap::set(int x, int y, const Tile& t)
    {
        // DOES NOTHING!
    }

    void
    EdgeMap::clear(int x, int y)
    {
        // DOES NOTHING!
    }

} // namespace lite
