#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vector2.h"
#include "Rect.h"

namespace lite
{
    class Camera
    {
        public:
        Camera(const Vector2& position, float viewWidth, float viewHeight);
        
        // The rounded position of the Camera
        const Vector2& position() const;
        
        void position(const Vector2& val);

        const Vector2& realPosition() const;
        const FloatRect& visibleArea() const;
        
        protected:
        Vector2 _position;
        Vector2 _roundedPosition;

        FloatRect _visibleArea;
    };
} // namespace lite
#endif
