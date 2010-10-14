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
        if(x < (int)width() && x >= 0 &&
           y < (int)height() && y >= 0)
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
        Tile* newTile;
        Tile* old = _tiles[x][y];

        if(old != NULL)
        {
            delete _tiles[x][y];
        }

        // Prevent useless tiles from being added:
        if (t.isEmpty())
            newTile = NULL;
        else
            newTile = new Tile(t);

        Tile* above = y > 0 ? get(x, (y - 1)) : NULL;
        Tile* left = x > 0 ? get((x - 1), y) : NULL;
        Tile* below = y < (int)height() - 1 ? get(x, (y + 1)) : NULL;
        Tile* right = x < (int)width() - 1 ? get((x + 1), y) : NULL;
        
        // We're "removing" a tile, so we restore
        //  adjacent tiles' adjacent edges to their initial values.
        if (newTile == NULL)
        {
            if (above != NULL)
                above->edges()[BOTTOM] = above->initialEdges()[BOTTOM];
            if (left != NULL)
                left->edges()[RIGHT] = left->initialEdges()[RIGHT];
            if (below != NULL)
                below->edges()[TOP] = below->initialEdges()[TOP];
            if (right != NULL)
                right->edges()[LEFT] = right->initialEdges()[LEFT];
        }
        else
        {
            // Special edge cases (no pun intended):
            if (x == 0) // left edge of the map
            {
                newTile->edges()[LEFT] = NONE;
            }
            else if (x == (width() - 1)) // right edge of the map
            {
                newTile->edges()[RIGHT] = NONE;
            }

            if (y == 0) // top edge of the map
            {
                newTile->edges()[TOP] = NONE;
            }
            else if (y == (height() - 1)) // bottom edge of the map
            {
                newTile->edges()[BOTTOM] = NONE;
            }

            // Else, we're adding a tile, so we clear all adjacent
            //  edges that we have solid edges for.
            if (above != NULL)
            {
                if (newTile->initialEdges()[TOP] && above->initialEdges()[BOTTOM])
                {
                    newTile->edges()[TOP] = NONE;
                    above->edges()[BOTTOM] = NONE;
                }
                else
                {
                    above->edges()[BOTTOM] = above->initialEdges()[BOTTOM];
                }
            }

            if (left != NULL)
            {
                if (newTile->initialEdges()[LEFT] && left->initialEdges()[RIGHT])
                {
                    newTile->edges()[LEFT] = NONE;
                    left->edges()[RIGHT] = NONE;
                }
                else
                {
                    left->edges()[RIGHT] = left->initialEdges()[RIGHT];
                }
            }

            if (below != NULL)
            {
                if (newTile->initialEdges()[BOTTOM] && below->initialEdges()[TOP])
                {
                    newTile->edges()[BOTTOM] = NONE;
                    below->edges()[TOP] = NONE;
                }
                else
                {
                    below->edges()[TOP] = below->initialEdges()[TOP];
                }
            }

            if (right != NULL)
            {
                if (newTile->initialEdges()[RIGHT] && right->initialEdges()[LEFT])
                {
                    newTile->edges()[RIGHT] = NONE;
                    right->edges()[LEFT] = NONE;
                }
                else
                {
                    right->edges()[LEFT] = right->initialEdges()[LEFT];
                }
            }

        }

        _tiles[x][y] = newTile;
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
