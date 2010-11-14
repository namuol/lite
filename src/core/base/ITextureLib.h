#ifndef _ITEXTURELIB_H_
#define _ITEXTURELIB_H_
#include "IDataLib.h"
#include "ITexture.h"

namespace lite
{
    class ITextureLib : public IDataLib<ITexture>
    {
        protected:
        virtual ITexture* _load(const string& full_path);
        virtual void _unload(ITexture* item);
    };

} // namespace lite
#endif

