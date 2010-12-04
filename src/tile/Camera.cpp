#include "Vector2.h"
#include "Rect.h"

#include "Camera.h"

namespace lite {
    Camera::Camera():
        _position(),
        _roundedPosition(),
        _visibleArea()
    {
    }

    Camera::Camera(const Vector2& position, float viewWidth, float viewHeight)
    {
        this->position(position);
        _visibleArea.width = viewWidth;
        _visibleArea.height = viewHeight;
    }

    // The rounded position of the Camera
    const Vector2&
    Camera::position() const
    {
        //return _roundedPosition;
        return _position;
    }

    void
    Camera::position(const Vector2& val)
    {
        _position = val;
        _visibleArea.x = _position.x;
        _visibleArea.y = _position.y;
        //_roundedPosition = Vector2((float)((int)_position.x + 0.5f), (float)((int)_position.y + 0.5f));
    }

    const Vector2&
    Camera::realPosition() const
    {
        return _position;
    }

    const FloatRect&
    Camera::visibleArea() const
    {
        return _visibleArea;
    }

    const Vector2&
    Camera::offsetFrom(const Vector2& worldPos) const
    {
        return worldPos - _position;
    }

} // namespace lite
