#include <SFML/Graphics.hpp>

#include "ITexture.h"

#include "SFMLTexture.h"
#include "SFMLTextureLib.h"

namespace lite
{
    ITexture*
    SFMLTextureLib::_load(const string& full_path)
    {
        sf::Image* img = new sf::Image();
        if( img->LoadFromFile(full_path) )
            return new SFMLTexture(img);
        else
            return NULL;
    }

    void
    SFMLTextureLib::_unload(ITexture* item)
    {
        SFMLTexture* tex = dynamic_cast<SFMLTexture*>(item);
        delete tex->img();
        delete tex;
    }

} // namespace lite
