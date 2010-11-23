#ifndef _TEXTSTRING_H_
#define _TEXTSTRING_H_

#include <string>
using std::string;

#include "TextureGrid.h"
#include "Vector2.h"
#include "Sprite.h"
#include "IDrawTarget.h" // for BlendMode and IDrawTarget
#include "Color.h"
    
namespace lite
{
    class ITexture;

    class TextString : public Sprite
    {
        public:
        TextString(IDrawTarget* drawTarget,
               const TextureGrid& texGrid,
               const string& text,
               int offset=0,
               float drawOrder=0.f,
               const Vector2& position=Vector2(0.f,0.f),
               float scalex=1.f, float scaley=1.f,
               float rotation=0.f,
               const Color& rgba=Color::WHITE,
               Blend::Mode mode=Blend::ALPHA);

        TextString(const TextString& other);

        const ITexture* tex() const;
        void tex(ITexture* val);

        virtual void draw(int dt) const; 
        
        const TextureGrid& texGrid() const;
        void texGrid(const TextureGrid& val);

        const string& text() const;

        int offset() const;
        void offset(int val);

        virtual float text_xoffset_at(unsigned int index) const;
        virtual float text_yoffset_at(unsigned int index) const;
        virtual float text_scalex_at(unsigned int index) const;
        virtual float text_scaley_at(unsigned int index) const;
        virtual float text_rotation_at(unsigned int index) const;
        virtual Color text_color_at(unsigned int index) const;
        virtual Blend::Mode text_blendmode_at(unsigned int index) const;

        protected:
        const TextureGrid& _texGrid;
        string _text;
        int _offset;
    };
} // namespace lite
#endif
