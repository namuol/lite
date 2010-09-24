#ifndef _SUBTEXTURESHEET_H_
#define _SUBTEXTURESHEET_H_

#include <string>

#include <vector>
using std::vector;

#include <SFML/Graphics.hpp>
using sf::Image;

#include <SFML/Rect.hpp>
using sf::IntRect;

class SubTexture;

namespace lite
{

    class SubTextureSheet
    {
        public:
        SubTextureSheet(const string& name,
                        const Image* texture, 
                        int subTextureWidth, 
                        int subTextureHeight);

        const string& name() const;
        const Image* texture() const;
        const IntRect& rectangle() const;

        const SubTexture* operator[](int index) const;

        // Width/height in number of subTextures:
        int width() const;
        int height() const;
        int subTextureWidth() const;
        int subTextureHeight() const;

        protected:
        string _name; // necessary?
        Image* _texture;
        int _width, _height;

        vector<SubTexture*> _subTextures;

        // The dimensions of a single subTexture (used to slice up
        //  the main texture into a grid:
        IntRect _rectangle; 
        
        // The texture coordinates for each subTexture:
        vector<IntRect> _rectangles;
    };

} // namespace lite

#endif
