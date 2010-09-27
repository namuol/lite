#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "IDrawable.h"
#include "ITexture.h"
    
namespace lite
{
    class Sprite : public IDrawable
    {
        public:
        Sprite(ITexture* tex,
               float x=0.f, float y=0.f,
               float scalex=0.f, float scaley=0.f,
               float rotation=0.f):
            _tex(tex),
            _x(x),
            _y(y),
            _scalex(scalex),
            _scaley(scaley),
            _rotation(rotation)
        {
        }

        const ITexture* tex() const { return _tex; }
        void tex(ITexture* val) { _tex = val; }

        float scalex() const { return _scalex; }
        void scalex(float val) { _scalex = val; }

        float scaley() const { return _scaley; }
        void scaley(float val) { _scaley = val; }

        float width() const { return _tex->width() * _scalex; }
        void width(float val) const { _scalex = val / _tex->width(); }

        float height() const { return _tex->height() * _scaley; }
        void height(float val) const { _scaley = val / _tey->height(); }

        float rotation() const { return _rotation; }
        void rotation(float val) { _rotation = val; }

        virtual void
        draw() const
        {
            drawTarget->drawTexture(
                _tex,
                _x, _y,
                _scalex, _scaley,
                _rotation
            );
        }

        protected:
        ITexture* _tex;
        float _x,_y;
        float _scalex,_scaley;
        float _rotation;
        // bool flipx,flipy; //TODO
    };
} // namespace lite
#endif
