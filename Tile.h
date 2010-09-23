#ifndef _TILE_H_
#define _TILE_H_

#include <vector>
using std::vector;

#include "Edge.h"

namespace lite
{
    class SubTexture;

    // A single layer of a tile.
    // Essentially just a texture and a z-index.
    class SubTile : IHasZ
    {
        public:
        SubTile()
        : _texture(NULL), _z(0.0)
        {
        }

        SubTile(const SubTexture* texture, z=0.0)
        : _texture(texture), _z(z)
        {
        }

        float z() const;
        float z(float value) { _z = value; }

        private:
        const SubTexture* _texture;
        float _z;
    }

    class Tile
    {
        public:
        Tile(const Tile& other);
        Tile(const vector<SubTile>& subTiles);
        Tile(const vector<SubTile>& subTiles, const EdgeArray& edges);
        
        const EdgeArray& edges() const;
    
        const EdgeArray& initialEdges() const;

        const vector<SubTile>& subTiles() const;
   
        bool isSolid();
        void setSolid(bool solidOrNot);

        bool isEmpty();

        protected:
        vector<SubTile> _subTiles;

        EdgeArray _initialEdges;
        EdgeArray _edges;
    };

} // namespace lite

#endif
