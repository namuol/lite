#include "World.h"
#include "Vector2.h"
#include "Camera.h"
#include "WorldObject.h"

namespace lite
{
    WorldObject::WorldObject(const World* world, const Vector2& position):
        _world(world),
        _position(position)
    {
    }

    WorldObject::WorldObject(const WorldObject& other):
        _world(other.world()),
        _position(other.position())
    {
    }

    const World*
    WorldObject::world() const
    {
        return _world;
    }

    void
    WorldObject::world(const World* val)
    {
        _world = val;
    }


    const Vector2&
    WorldObject::position() const
    {
        return _position;
    }

    void
    WorldObject::position(const Vector2& val)
    {
        _position = val;
    }


    const Vector2&
    WorldObject::camPosition() const
    {
        return _world->cam().offsetFrom(_position);
    }

    void
    WorldObject::camPosition(const Vector2& val)
    {
        _position = -_world->cam().offsetFrom(val);
    }


    void
    WorldObject::update(int dt)
    {
    }

} // namespace lite
