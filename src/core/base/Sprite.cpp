#include "Vector2.h"
#include "IDrawTarget.h"
#include "IDrawable.h"
#include "ITexture.h"

#include "Sprite.h"

namespace lite
{
    Sprite::Sprite(IDrawTarget* drawTarget,
           const lite::ITexture* tex,
           float drawOrder,
           const Vector2& position,
           float scalex, float scaley,
           float rotation):
        IDrawable(drawTarget, drawOrder),
        _tex(tex),
        _position(position),
        _scalex(scalex),
        _scaley(scaley),
        _rotation(rotation)
    {
    }

    const ITexture*
    Sprite::tex() const
    {
        return _tex;
    }
    
    void
    Sprite::tex(ITexture* val)
    {
        _tex = val;
    }
    

    const Vector2&
    Sprite::position() const
    {
        return _position;
    }
    

    float
    Sprite::scalex() const
    {
        return _scalex;
    }
    
    void
    Sprite::scalex(float val)
    {
        _scalex = val;
    }
    

    float
    Sprite::scaley() const
    {
        return _scaley;
    }
    
    void
    Sprite::scaley(float val)
    {
        _scaley = val;
    }
    

    float
    Sprite::width() const
    {
        return _tex->width() * _scalex;
    }
    
    void
    Sprite::width(float val)
    {
        _scalex = val / _tex->width();
    }
    

    float
    Sprite::height() const
    {
        return _tex->height() * _scaley;
    }
    
    void
    Sprite::height(float val)
    {
        _scaley = val / _tex->height();
    }
    

    float
    Sprite::rotation() const
    {
        return _rotation;
    }
    
    void
    Sprite::rotation(float val)
    {
        _rotation = val;
    }
    

    void
    Sprite::draw(int dt) const
    {
        drawTarget->drawTexture(
            _tex,
            _position.x, _position.y,
            _scalex, _scaley,
            _rotation
        );
    }

} // namespace lite
