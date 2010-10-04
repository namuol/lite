#ifndef _SFMLTEXTURELSFMLB_H_
#define _SFMLTEXTURELSFMLB_H_
#include <SFML/Graphics.hpp>

#include "ITextureLib.h"

#include "SFMLTexture.h"

namespace lite
{
    class ITexture;
    class SFMLTextureLib : public ITextureLib
    {
        protected:
        // Pure-virtual load/unload routines must be defined
        //  by inherited class.
        virtual ITexture* _load(const string& full_path)
        {
            sf::Image* img = new sf::Image();
            if( img->LoadFromFile(full_path) )
                return new SFMLTexture(img);
            else
                return NULL;
        }

        virtual void _unload(ITexture* item)
        {
            SFMLTexture* tex = dynamic_cast<SFMLTexture*>(item);
            delete tex->img();
            delete tex;
        }
    };
} // namespace lite
#endif

