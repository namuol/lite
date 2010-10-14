#include <cmath>

#include "IDrawTarget.h"

#include "Camera.h"
#include "Tile.h"
#include "ITileMap.h"

#include "TileMapLayer.h"

#include <iostream>
using namespace std;

namespace lite
{
    TileMapLayer::TileMapLayer(IDrawTarget* target, const ITileMap& tileMap, 
                            const Camera& cam, unsigned int layerIndex,
                            float drawOrder, float scrollSpeed):
        IDrawable(target, drawOrder),
        _tileMap(tileMap),
        _cam(cam),
        _scrollSpeed(scrollSpeed),
        _layerIndex(layerIndex)
    {
    }
    
    const ITileMap&
    TileMapLayer::tileMap() const
    {
        return _tileMap;
    }


    void
    TileMapLayer::draw(int dt) const
    {
        Vector2 camPos = _cam.position();
        float cam_x = camPos.x * _scrollSpeed;
        float cam_y = camPos.y * _scrollSpeed;
        float cam_w = _cam.visibleArea().width;
        float cam_h = _cam.visibleArea().height;

        int _startX = (int)floor(cam_x / _tileMap.tileWidth());
        int _startY = (int)floor(cam_y / _tileMap.tileHeight());

        int _endX = (int)ceil(((cam_x + cam_w) / _tileMap.tileWidth()));
        int _endY = (int)ceil(((cam_y + cam_h) / _tileMap.tileHeight()));

        for (int x = _startX; x < _endX; ++x)
        {
            for (int y = _startY; y < _endY; ++y)
            {
                Vector2 position = Vector2(x * _tileMap.tileWidth(), 
                                           y * _tileMap.tileHeight()) - camPos + 
                                    (camPos - camPos * _scrollSpeed);
                int modX, modY;
                if (_scrollSpeed != 1.0f)
                {
                    if (x >= 0)
                        modX = x % _tileMap.width();
                    else
                        modX = _tileMap.width() - (-x) % _tileMap.width();

                    if (y >= 0)
                        modY = y % _tileMap.height();
                    else
                        modY = _tileMap.height() - (-y) % _tileMap.height();
                }
                else 
                {
                    modX = x;
                    modY = y;
                }

                position.x = round(position.x);
                position.y = round(position.y);
                const Tile* tile = _tileMap.get(modX,modY);
                if (tile != NULL)
                {
                    for (unsigned int subLayerIndex = 0;
                        subLayerIndex < _tileMap.subLayerCount();
                        ++subLayerIndex)
                    {
                        const ITexture* texture = tile->textures()[_layerIndex][subLayerIndex];
                        if (texture != NULL)
                        {
                            drawTarget->drawTexture(texture, position.x, position.y);
                        }
                    }

                } // if (tile !+ NULL)

            } // for (int y = startY; y < endY; ++y)

        } // for (int x = startX; x < endX; ++x)

    }

    // This simple mechanism is used to control which tiles are rendered:
    //  for each X between startX and endX
    //    for each Y between startY and endY
    //      draw tileMap[X,Y].textures
    //
    // So a game would have to update these start-end values whenever the camera
    //  moves in order to see the correct tiles.
    /*
    int
    TileMapLayer::startX() const
    {
        return _startX;
    }

    int
    TileMapLayer::startY() const
    {
        return _startY;
    }

    int
    TileMapLayer::endX() const
    {
        return _endX;
    }

    int
    TileMapLayer::endY() const
    {
        return _endY;
    }
    */

    float
    TileMapLayer::scrollSpeed() const
    {
        return _scrollSpeed;
    }

    void
    TileMapLayer::scrollSpeed(float val)
    {
        _scrollSpeed = val;
    }

} // namespace lite
