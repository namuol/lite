#include <vector>
using std::vector;

#include "Rect.h"
#include "ITexture.h"

#include "SubTextureSheet.h"
#include "SubTexture.h"

namespace lite
{

    SubTexture::SubTexture(const SubTextureSheet* sheet, int index):
        _sheet(sheet),
        _index(index),
        _rectangle(_sheet->rectangles[_index])
    {
    }

    const SubTextureSheet*
    SubTexture::sheet() const
    {
        return _sheet;
    }

    int
    index() const
    {
        return _index;
    }

    const ITexture*
    SubTexture::texture() const
    {
        return _sheet->_texture;
    }

    const Rect&
    SubTexture::rect() const
    {
        return _rectangle;
    }

} // namespace lite
