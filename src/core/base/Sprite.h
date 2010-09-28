#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Vector2.h"
#include "IDrawTarget.h"
#include "IDrawable.h"
#include "ITexture.h"
    
namespace lite
{
    class Sprite : public IDrawable
    {
        public:
        Sprite(IDrawTarget* drawTarget,
               const ITexture* tex,
               float drawOrder=0.f,
               const Vector2& position=Vector2(0.f,0.f),
               float scalex=1.f, float scaley=1.f,
               float rotation=0.f):
            IDrawable(drawTarget),
            _tex(tex),
            _position(position),
            _scalex(scalex),
            _scaley(scaley),
            _rotation(rotation)
        {
        }

        const ITexture* tex() const { return _tex; }
        void tex(ITexture* val) { _tex = val; }

        const Vector2& position() const { return _position; }

        float scalex() const { return _scalex; }
        void scalex(float val) { _scalex = val; }

        float scaley() const { return _scaley; }
        void scaley(float val) { _scaley = val; }

        float width() const { return _tex->width() * _scalex; }
        void width(float val) { _scalex = val / _tex->width(); }

        float height() const { return _tex->height() * _scaley; }
        void height(float val) { _scaley = val / _tex->height(); }

        float rotation() const { return _rotation; }
        void rotation(float val) { _rotation = val; }

        virtual void
        draw(int dt) const
        {
            drawTarget->drawTexture(
                _tex,
                _position.x, _position.y,
                _scalex, _scaley,
                _rotation
            );
        }

        protected:
        const ITexture* _tex;
        Vector2 _position;
        float _scalex,_scaley;
        float _rotation;
        // bool flipx,flipy; //TODO
    };
} // namespace lite
#endif
