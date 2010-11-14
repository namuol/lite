#include "TextureSheet.h"
#include "ITexture.h"

namespace lite
{
    TextureSheet::TextureSheet():
        _tex(NULL)
    {
    }

    TextureSheet::TextureSheet(const ITexture* tex):
        _tex(tex)
    {
    }

    const ITexture*
    TextureSheet::operator[](const IntRect& subrect)
    {
        if( _subtextures.find(subrect) == _subtextures.end() )
        {
            create(subrect);
        }
        return _subtextures[subrect];
    }

    const ITexture*
    TextureSheet::create(const IntRect& subrect)
    {
        const ITexture* subtex = _tex->sub_texture(subrect);
        _subtextures[subrect] = subtex;
        return _subtextures[subrect];
    }

} // namespace lite
