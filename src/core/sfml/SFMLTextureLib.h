#ifndef _SFMLTEXTURELSFMLB_H_
#define _SFMLTEXTURELSFMLB_H_

#include "ITextureLib.h"

namespace lite
{
    class ITexture;
    class SFMLTexture;
    class SFMLTextureLib : public ITextureLib
    {
        protected:
        virtual ITexture* _load(const string& full_path);

        virtual void _unload(ITexture* item);
    };
} // namespace lite
#endif

