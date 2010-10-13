#ifndef _TILEMAPLAYER_H_
#define _TILEMAPLAYER_H_

#include <vector>
using std::vector;

#include <map>
using std::map;

#include "IDrawable.h"
#include "ITexture.h"

#include "Edge.h"

namespace lite
{
    class ICamera;
    class IDrawTarget;
    class TileMap;

    class TileMapLayer : public IDrawable
    {
        public:
        TileMapLayer(IDrawTarget* target, const TileMap* tileMap, const ICamera* cam,
                     float drawOrder=0.f);
        
        const TileMap* tileMap() const;


        virtual void draw(int dt) const;

        // This simple mechanism is used to control which tiles are rendered:
        //  for each X between startX and endX
        //    for each Y between startY and endY
        //      draw tileMap[X,Y].textures
        //
        // So a game would have to update these start-end values whenever the camera
        //  moves in order to see the correct tiles.

        unsigned int startX() const;
        void startX(unsigned int val);

        unsigned int startY() const;
        void startY(unsigned int val);

        unsigned int endX() const;
        void endX(unsigned int val);

        unsigned int endY() const;
        void endY(unsigned int val);


        float scrollSpeed() const;
        void scrollSpeed(float val);

        protected:
        unsigned int _startX, _startY, _endX, _endY;
        const TileMap* _tileMap;

        const ICamera* _cam;

        float _scrollSpeed;
        unsigned int _layerIndex;
    };
} // namespace lite

#endif
