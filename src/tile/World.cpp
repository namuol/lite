#include "WorldObject.h"

#include "World.h"

namespace lite
{
    World::World(ITileMap& tileMap):
        _tileMap(tileMap),
        _worldObjects(),
        _otherMaps(),
        _interactiveLayers(),
        _parallaxLayers()
    {
    }

    const list<WorldObject*>&
    World::worldObjects() const
    {
        return _worldObjects;
    }

    void
    World::addWorldObject(WorldObject* worldObject)
    {
        _worldObjects.push_back(worldObject);
    }

    void
    World::remWorldObject(WorldObject* worldObject)
    {
        _worldObjects.remove(worldObject);
    }


    const ITileMap&
    World::tileMap() const
    {
        return _tileMap;
    }

    void
    World::tileMap(ITileMap& val) const
    {
        _tileMap = val;
    }

    const list<ITileMap*>&
    World::otherMaps() const
    {
        return _otherMaps;
    }


    const list<const TileMapLayer*>&
    World::interactiveLayers() const
    {
        return _interactiveLayers;
    }

    void
    World::addInteractiveLayer(const TileMapLayer* layer)
    {
        _interactiveLayers.push_back(layer);
    }

    void
    World::remInteractiveLayer(const TileMapLayer* layer)
    {
        _interactiveLayers.remove(layer);
    }

    const list<const TileMapLayer*>&
    World::parallaxLayers() const
    {
        return _parallaxLayers;
    }

    void
    World::addParallaxLayer(const TileMapLayer* layer)
    {
        _parallaxLayers.push_back(layer);
    }

    void
    World::remParallaxLayer(const TileMapLayer* layer)
    {
        _parallaxLayers.remove(layer);
    }


    const Camera&
    World::cam() const
    {
        return _cam;
    }

    void
    World::cam(const Camera& val)
    {
        _cam = val;
    }

} // namespace lite
