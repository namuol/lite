#ifndef _TEXTURESHEET_H_
#define _TEXTURESHEET_H_

#include <map>
using std::map;

#include <vector>
using std::vector;

#include "ITexture.h"
#include "Rect.h"

#include <iostream>
using std::cout;
using std::endl;

namespace lite
{
    class TextureSheet
    {
        public:
        TextureSheet();

        TextureSheet(const ITexture* tex);

        const ITexture* operator[](const IntRect& subrect);

        protected:
        const ITexture* create(const IntRect& subrect);

        const ITexture* _tex;
        map<IntRect, const ITexture*> _subtextures;
    };

} // namespace lite
#endif
