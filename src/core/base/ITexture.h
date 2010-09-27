#ifndef _ITEXTURE_H_
#define _ITEXTURE_H_
namespace lite
{
    class ITexture
    {
        public:
        ITexture(int width, int height):
            _width(width),
            _height(height)
        {
        }

        virtual int width() const { return _width; }
        virtual int height() const { return _height; }

        protected:
        int _width, _height;
    };
} // namespace lite
#endif
