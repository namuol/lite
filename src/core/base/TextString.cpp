#include "TextureGrid.h"
#include "Vector2.h"
#include "IDrawTarget.h"
#include "ITexture.h"

#include "TextString.h"

namespace lite {

    TextString::TextString(IDrawTarget* drawTarget,
           const TextureGrid& texGrid,
           const string& text,
           int offset,
           float drawOrder,
           const Vector2& position,
           float scalex, float scaley,
           float rotation,
           const Color& rgba,
           Blend::Mode mode):
        Sprite(drawTarget,
               NULL,
               drawOrder,
               position,
               scalex, scaley,
               rotation,
               rgba,
               mode),
        _texGrid(texGrid),
        _text(text),
        _offset(offset)
    {
    }

    const ITexture*
    TextString::tex() const
    {
        return NULL;
    }

    void
    TextString::tex(ITexture* val)
    {
        // TODO: Debug warning message. 
    }


    void
    TextString::draw(int dt) const
    {
        for(unsigned int i=0; i<_text.size(); ++i)
        {
            const ITexture* tex = _texGrid[((int)_text[i]) + _offset];
            if(tex) {
                drawTarget->drawTexture(
                    tex,
                    _position.x + (_texGrid.sub_width() * i * _scalex)
                        + text_xoffset_at(i),
                    _position.y + text_yoffset_at(i),
                    text_scalex_at(i),
                    text_scaley_at(i),
                    text_rotation_at(i),
                    text_color_at(i),
                    text_blendmode_at(i)
                );
            }
        }
    }

    
    const TextureGrid&
    TextString::texGrid() const
    {
        return _texGrid;
    }

    void
    TextString::texGrid(const TextureGrid& val)
    {
        //_texGrid = val; // TODO WTF
    }


    const string&
    TextString::text() const
    {
        return _text;
    }

    int
    TextString::offset() const
    {
        return _offset;
    }

    void
    TextString::offset(int val)
    {
        _offset = val;
    }
    
    float
    TextString::text_xoffset_at(unsigned int index) const
    {
        return 0;;
    }

    float
    TextString::text_yoffset_at(unsigned int index) const
    {
        return 0;_position.y;
    }


    float
    TextString::text_scalex_at(unsigned int index) const
    {
        return _scalex;
    }

    float
    TextString::text_scaley_at(unsigned int index) const
    {
        return _scaley;
    }

    float
    TextString::text_rotation_at(unsigned int index) const
    {
        return _rotation;
    }

    Color
    TextString::text_color_at(unsigned int index) const
    {
        return _rgba;
    }

    Blend::Mode
    TextString::text_blendmode_at(unsigned int index) const
    {
        return _mode;
    }
} // namespace lite
