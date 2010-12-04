#ifndef _HOTSPOT_H_
#define _HOTSPOT_H_

#include "WorldObject.h"

namespace lite
{
    class Hotspot : public IUpdateable
    {
        public:
        Hotspot(const Hotspot& other);
        Hotspot(WorldObject& obj, const Vector2& offset=Vector2(0,0));

        void worldObject(WorldObject& val);
        WorldObject& worldObject() const;
        
        void offset(const Vector2& val);
        const Vector2& offset() const;

        void position(const Vector2& val);
        const Vector2& position() const;

        int tileX() const;
        int tileY() const;

        bool didCollide() const;

        virtual void update(int dt);

        protected:
        WorldObject& _worldObject;
        Vector2 _offset;
        Vector2 _position;
        bool _didCollide;
    };

    class TopHotspot : public Hotspot
    {
        public:
        virtual void update(int dt);
    };

    class BottomHotspot : public Hotspot
    {
        public:
        virtual void update(int dt);
    };

    class SideHotspot : public Hotspot
    {
        public:
        void update(int dt);

        protected:
        virtual bool left() const = 0;
    };

    class LeftHotspot : public SideHotspot
    {
        protected:
        bool left() const { return true; };
    };

    class RightHotspot : public SideHotspot
    {
        protected:
        bool left() const { return false; };
    };
    
} // namespace lite

#endif
