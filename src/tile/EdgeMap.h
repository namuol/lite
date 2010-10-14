#ifndef _EDGEMAP_H_
#define _EDGEMAP_H_

#include "ITileMap.h"

#include <vector>
using std::vector;

namespace lite
{
    class Tile;
    class ITexture;

    class EdgeMap : public ITileMap
    {
        public:
        EdgeMap(
            const ITileMap* tileMap,
            const ITexture* topTex,
            const ITexture* leftTex,
            const ITexture* bottomTex,
            const ITexture* rightTex
        );

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
        
        virtual ~EdgeMap();

        protected:
        const ITileMap* _tileMap;

        const ITexture* _topTex;
        const ITexture* _leftTex;
        const ITexture* _bottomTex;
        const ITexture* _rightTex;

        vector<Tile*> _edgeTiles;
    };


} // namespace lite

#endif
