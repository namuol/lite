#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Vector2.h"
#include "Rect.h"

namespace lite
{
    class Camera
    {
        public:
        Camera();
        Camera(const Vector2& position, float viewWidth, float viewHeight);
        
        // The rounded position of the Camera
        const Vector2& position() const;
        
        void position(const Vector2& val);

        // TODO: Figure out wtf this is for...
        const Vector2& realPosition() const;
        const FloatRect& visibleArea() const;

        // Return the position relative to the camera's world position:
        const Vector2& offsetFrom(const Vector2& worldPos) const;
        
        protected:
        Vector2 _position;
        Vector2 _roundedPosition;

        FloatRect _visibleArea;
    };
} // namespace lite
#endif
