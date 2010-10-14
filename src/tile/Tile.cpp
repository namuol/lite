#include <vector>
using std::vector;

#include "Edge.h"
#include "Tile.h"

namespace lite
{
    Tile::Tile(const Tile& other):
        _textures(other.textures()),
        _initialEdges(other.initialEdges()),
        _edges(other.edges())
    {
    }

    Tile::Tile(unsigned int layerCount, unsigned int subLayerCount):
        _textures(layerCount, vector<const ITexture*>(subLayerCount)),
        _initialEdges(),
        _edges()
    {
    }

    Tile::Tile(const vector<vector<const ITexture*> >& textures):
        _textures(textures),
        _initialEdges(),
        _edges()
    {
    }

    Tile::Tile(const vector<vector<const ITexture*> >& textures,
               const EdgeArray& edges):
        _textures(textures),
        _initialEdges(edges),
        _edges(edges)
    {
    }

    const EdgeArray&
    Tile::edges() const
    {
        return _edges;
    }

    EdgeArray&
    Tile::edges()
    {
        return _edges;
    }

    const EdgeArray&
    Tile::initialEdges() const
    {
        return _initialEdges;
    }

    EdgeArray&
    Tile::initialEdges()
    {
        return _initialEdges;
    }

    bool
    Tile::isSolid() const
    {
        bool solid = false;
        for(int i=0; i<4; ++i)
        {
            if(_edges[i])
            {
                solid = true;
                break;
            }
        }
        return solid;   
    }

    void
    Tile::setSolid(bool solidOrNot)
    {
        for (int i=0; i<4; ++i)
        {
            _initialEdges[i] = solidOrNot ? SOLID : NONE;
            _edges[i] = solidOrNot ? SOLID : NONE;
        }
    }


    bool
    Tile::isEmpty() const
    {
        for (int i=0; i<4; ++i)
        {
            // If we have any edges...
            if(_initialEdges[i])
            {
                return false; // We aren't empty.
            }
        }
        
        for(unsigned int i=0; i<layerCount(); ++i)
        {
            for(unsigned int j=0; j<subLayerCount(); ++j)
            {
                if(_textures[i][j] != NULL)
                {
                    // Or if we have any texture data...
                    return false; // We aren't empty.
                }
            }
        }

        // Otherwise, we *are* empty!
        return true;
    }

    unsigned int
    Tile::layerCount() const
    {
        return _textures.size();
    }

    unsigned int
    Tile::subLayerCount() const
    {
        return _textures[0].size();
    }


    const vector<vector<const ITexture*> >&
    Tile::textures() const
    {
        return _textures;
    }


} // namespace lite
