#ifndef _ITEXTURE_H_
#define _ITEXTURE_H_

#include "Rect.h"

namespace lite
{

    class ITexture
    {
        public:
        ITexture(int width, int height);

        virtual ITexture* sub_texture(const IntRect& rect) const = 0;

        virtual ~ITexture();
        
        virtual int width() const;
        virtual int height() const;
        
        const ITexture* root() const;
        const IntRect& rect() const;

        protected:
        ITexture(const ITexture* root, const IntRect& rect);

        private:
        const ITexture* _root;
        IntRect _rect;
    };
} // namespace lite
#endif
