#ifndef _ITEXTURE_H_
#define _ITEXTURE_H_

#include "Rect.h"

namespace lite
{
    class ITexture
    {
        public:
        ITexture(int width, int height):
            _root(NULL),
            _rect(0,0,width,height)
        {
        }

        virtual ITexture* sub_texture(const IntRect& rect) const = 0;

        virtual int width() const { return _rect.width; }
        virtual int height() const { return _rect.height; }
        
        const ITexture* root() const { return _root; }
        const IntRect& rect() const { return _rect; }

        protected:
        ITexture(const ITexture* root, const IntRect& rect):
            _root(root),
            _rect(rect)
        {
        }

        private:
        const ITexture* _root;
        IntRect _rect;
    };
} // namespace lite
#endif
