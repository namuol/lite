#include <cmath>

#include "WorldObject.h"
#include "Edge.h"
#include "Tile.h"
#include "TileMap.h"
#include "Vector2.h"

#include "Hotspot.h"

namespace lite
{
    Hotspot::Hotspot(const Hotspot& other):
        _worldObject(other.worldObject()),
        _offset(other.offset())
    {
    }

    Hotspot::Hotspot(WorldObject& worldObject, const Vector2& offset):
        _worldObject(worldObject),
        _offset(offset)
    {
    }

    void
    Hotspot::worldObject(WorldObject& val)
    {
        _worldObject = val;
    }

    WorldObject&
    Hotspot::worldObject() const
    {
        return _worldObject;
    }

    
    void
    Hotspot::offset(const Vector2& val)
    {
        _offset = val;
    }

    const Vector2&
    Hotspot::offset() const
    {
        return _offset;
    }


    void
    Hotspot::position(const Vector2& val)
    {
        _worldObject.position(val - _offset);
        _position = val;
    }

    const Vector2&
    Hotspot::position() const
    {
        return _position;
    }


    int
    Hotspot::tileX() const
    {
        const ITileMap& tm = _worldObject.world()->tileMap();
        return (int)floor(position().x / tm.tileHeight());
    }

    int
    Hotspot::tileY() const
    {
        const ITileMap& tm = _worldObject.world()->tileMap();
        return (int)floor(position().y / tm.tileWidth());
    }

    bool
    Hotspot::didCollide() const
    {
        return _didCollide;
    }


    void
    Hotspot::update(int dt)
    {
        _didCollide = false;
    }


    void
    TopHotspot::update(int dt)
    {
        Hotspot::update(dt);

        const ITileMap& tileMap = _worldObject.world()->tileMap();
        const Tile* tile = tileMap.get(tileX(),tileY());

        if(tile)
        {
            int tileHeight = tileMap.tileHeight();
            int tileBottom = tileY() * tileHeight - 1;

            if(tile->edges()[BOTTOM] && (tileBottom - _position.y) < (tileHeight/2))
            {
                position(Vector2(_position.y, tileBottom));
                _didCollide = true;
            }
        }

    }

    void
    BottomHotspot::update(int dt)
    {
        Hotspot::update(dt);

        const ITileMap& tileMap = _worldObject.world()->tileMap();
        const Tile* tile = tileMap.get(tileX(),tileY());

        if(tile)
        {
            int tileHeight = tileMap.tileHeight();
            int tileTop = (tileY()+1) * tileHeight;

            if(tile->edges()[TOP] && (_position.y - tileTop) < (tileHeight/2))
            {
                position(Vector2(_position.y, tileTop));
                _didCollide = true;
            }
        }

    }

    void
    SideHotspot::update(int dt)
    {
        Hotspot::update(dt);
        
        int x = tileX();
        int y = tileY();

        const ITileMap& tileMap = _worldObject.world()->tileMap();
        const Tile* tile = tileMap.get(x, y);

        if(tile)
        {
            if(left())
            {
                int tileWidth = tileMap.tileWidth();
                int tileRight = (x + 1) * tileWidth;
                if(tile->edges()[RIGHT] && (tileRight - _position.x) < (tileWidth/2))
                {
                    position(Vector2(tileRight - 1, _position.y));
                    _didCollide = true;
                }
            }
            else
            {
                int tileWidth = tileMap.tileWidth();
                int tileLeft = x * tileWidth;
                if(tile->edges()[LEFT] and (_position.x - tileLeft) < (tileWidth/2))
                {
                    position(Vector2(tileLeft, _position.y));
                    _didCollide = true;
                }
            }
        }
   
    }

} // namespace lite
