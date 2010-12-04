#ifndef _WORLD_H_
#define _WORLD_H_

#include <list>
using std::list;

#include <map>
using std::map;

#include "ITileMap.h"
#include "Vector2.h"
#include "Camera.h"

namespace lite
{
    class TileMapLayer;
    class WorldObject;

    class World
    {
        public:
        World(ITileMap& tileMap);
        
        const list<WorldObject*>& worldObjects() const;
        void addWorldObject(WorldObject* worldObject);
        void remWorldObject(WorldObject* worldObject);

        const ITileMap& tileMap() const;
        void tileMap(ITileMap& val) const;

        const list<ITileMap*>& otherMaps() const;

        const list<const TileMapLayer*>& interactiveLayers() const;
        void addInteractiveLayer(const TileMapLayer* layer);
        void remInteractiveLayer(const TileMapLayer* layer);

        const list<const TileMapLayer*>& parallaxLayers() const;
        void addParallaxLayer(const TileMapLayer* layer);
        void remParallaxLayer(const TileMapLayer* layer);

        const Camera& cam() const;
        void cam(const Camera& val);

        protected:

        ITileMap& _tileMap;
        list<WorldObject*> _worldObjects;

        list<ITileMap*> _otherMaps;

        list<const TileMapLayer*> _interactiveLayers;
        list<const TileMapLayer*> _parallaxLayers;

        Camera _cam;
    };

} // namespace lite

#endif
