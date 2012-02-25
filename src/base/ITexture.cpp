#include <cstdlib>

#include "ITexture.h"

namespace lite
{
    ITexture::ITexture(int width, int height):
        _root(NULL),
        _rect(0,0,width,height)
    {
    }

    ITexture::~ITexture()
    {
    } 

    int
    ITexture::width() const
    {
        return _rect.width;
    }

    int
    ITexture::height() const
    {
        return _rect.height;
    }

    const ITexture*
    ITexture::root() const
    {
        return _root;
    }

    const IntRect&
    ITexture::rect() const
    {
        return _rect;
    }

    // Protected:
    ITexture::ITexture(const ITexture* root, const IntRect& rect):
        _root(root),
        _rect(rect)
    {
    }

} // namespace lite
