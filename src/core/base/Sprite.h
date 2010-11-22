#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "Vector2.h"
#include "IDrawable.h"
#include "IDrawTarget.h" // for BlendMode and IDrawTarget
#include "Color.h"
    
namespace lite
{
    class ITexture;

    class Sprite : public IDrawable
    {
        public:
        Sprite(IDrawTarget* drawTarget,
               const lite::ITexture* tex,
               float drawOrder=0.f,
               const Vector2& position=Vector2(0.f,0.f),
               float scalex=1.f, float scaley=1.f,
               float rotation=0.f,
               const Color& rgba=Color::WHITE,
               Blend::Mode mode=Blend::ALPHA);

        virtual const ITexture* tex() const;
        virtual void tex(ITexture* val);
        
        virtual const Vector2& position() const;

        virtual float scalex() const;
        virtual void scalex(float val);

        virtual float scaley() const;
        virtual void scaley(float val);

        virtual void scale(float scalex, float scaley);
        virtual void scale(float scale);

        virtual float width() const;
        virtual void width(float val);

        virtual float height() const;
        virtual void height(float val);

        virtual float rotation() const;
        virtual void rotation(float val);

        virtual const Color& rgba() const;
        virtual void rgba(const Color& val);

        virtual Blend::Mode mode() const;
        virtual void mode(Blend::Mode val);

        virtual void draw(int dt) const; 

        protected:
        const ITexture* _tex;
        Vector2 _position;
        float _scalex,_scaley;
        float _rotation;
        Color _rgba;
        Blend::Mode _mode;
        // bool flipx,flipy; //TODO? Negative scales instead?
    };
} // namespace lite
#endif
