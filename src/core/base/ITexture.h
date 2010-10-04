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

        ITexture(const ITexture* parent, const IntRect& rect)
        {
            if( parent )
            {
                if( parent->root() != NULL )
                {
                    _root = parent->root();
                }
                else
                {
                    _root = parent;
                }

                _rect = IntRect(parent->rect().x, parent->rect().y,
                                rect.width, rect.height);
            }
            else
            {
                _root = NULL;
                _rect = rect;
            }
        }

        virtual int width() const { return _rect.width; }
        virtual int height() const { return _rect.height; }
        
        const ITexture* root() const { return _root; }
        const IntRect& rect() const { return _rect; }

        private:
        const ITexture* _root;
        IntRect _rect;
    };
} // namespace lite
#endif
