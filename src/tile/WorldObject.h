#ifndef _WORLDOBJECT_H_
#define _WORLDOBJECT_H_

#include "World.h"
#include "IUpdateable.h"
#include "Vector2.h"

namespace lite
{

    class WorldObject : public IUpdateable
    {
        public:
        WorldObject(const World* world, const Vector2& position);
        WorldObject(const WorldObject& other);
        
        const World* world() const;
        void world(const World* val);

        const Vector2& position() const;
        void position(const Vector2& val);

        const Vector2& camPosition() const;
        void camPosition(const Vector2& val);

        virtual void update(int dt);

        protected:
        const World* _world;
        Vector2 _position;
    };

} // namespace lite

#endif
