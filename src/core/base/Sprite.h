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

        const Color& rgba() const;
        void rgba(const Color& val);

        Blend::Mode mode() const;
        void mode(Blend::Mode val);

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
