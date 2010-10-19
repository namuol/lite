#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Vector2.h"
#include "IDrawable.h"
    
namespace lite
{
    class ITexture;
    class IDrawTarget;

    class Sprite : public IDrawable
    {
        public:
        Sprite(IDrawTarget* drawTarget,
               const lite::ITexture* tex,
               float drawOrder=0.f,
               const Vector2& position=Vector2(0.f,0.f),
               float scalex=1.f, float scaley=1.f,
               float rotation=0.f);

        const ITexture* tex() const;
        void tex(ITexture* val);

        const Vector2& position() const;

        float scalex() const;
        void scalex(float val);

        float scaley() const;
        void scaley(float val);

        float width() const;
        void width(float val);

        float height() const;
        void height(float val);

        float rotation() const;
        void rotation(float val);

        virtual void draw(int dt) const; 

        protected:
        const ITexture* _tex;
        Vector2 _position;
        float _scalex,_scaley;
        float _rotation;
        // bool flipx,flipy; //TODO
    };
} // namespace lite
#endif
