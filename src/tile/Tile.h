#ifndef _TILE_H_
#define _TILE_H_

#include <vector>
using std::vector;

#include "IDrawable.h"
#include "ITexture.h"

#include "Edge.h"

namespace lite
{
    class IDrawTarget;

    class Tile
    {
        public:
        Tile(const Tile& other);
        Tile(unsigned int layerCount, unsigned int subLayerCount);
        Tile(unsigned int layerCount, unsigned int subLayerCount,
            std::vector<const ITexture*>* textures);
        Tile(const vector< vector<const ITexture*> >& textures);
        Tile(const vector< vector<const ITexture*> >& textures, const EdgeArray& edges);
        
        const EdgeArray& edges() const;
        EdgeArray& edges();
    
        const EdgeArray& initialEdges() const;
        EdgeArray& initialEdges();

        bool isSolid() const;
        void setSolid(bool solidOrNot);

        bool isEmpty() const;

        unsigned int layerCount() const;
        unsigned int subLayerCount() const;

        const vector< vector<const ITexture*> >& textures() const;
    
        protected:
        vector<vector<const ITexture*> > _textures;

        EdgeArray _initialEdges;
        EdgeArray _edges;
    };

} // namespace lite

#endif
