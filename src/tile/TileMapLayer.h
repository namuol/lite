#ifndef _TILEMAPLAYER_H_
#define _TILEMAPLAYER_H_

#include <vector>
using std::vector;

#include <map>
using std::map;

#include "IDrawable.h"
#include "ITexture.h"
#include "Color.h"

#include "Edge.h"

namespace lite
{
    class Camera;
    class IDrawTarget;
    class ITileMap;

    class TileMapLayer : public IDrawable
    {
        public:
        TileMapLayer(IDrawTarget* target, const ITileMap& tileMap, const Camera& cam,
                     unsigned int layerIndex, float drawOrder=0.f,
                     float scrollSpeed=1.f,
                     const Color& rgba=Color::WHITE,
                     Blend::Mode mode=Blend::ALPHA);
        
        const ITileMap& tileMap() const;


        virtual void draw(int dt) const;

        // This simple mechanism is used to control which tiles are rendered:
        //  for each X between startX and endX
        //    for each Y between startY and endY
        //      draw tileMap[X,Y].textures
        //
        // So a game would have to update these start-end values whenever the camera
        //  moves in order to see the correct tiles.

        /*
        int startX() const;

        int startY() const;

        int endX() const;

        int endY() const;
        */

        float scrollSpeed() const;
        void scrollSpeed(float val);

        unsigned int layerIndex() const;
        void layerIndex(unsigned int val);

        Blend::Mode mode() const;
        void mode(Blend::Mode val);

        protected:
        //int _startX, _startY, _endX, _endY;
        const ITileMap& _tileMap;

        const Camera& _cam;

        float _scrollSpeed;
        unsigned int _layerIndex;
        Color _rgba;
        Blend::Mode _mode;
    };
} // namespace lite

#endif
