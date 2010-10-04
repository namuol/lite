#ifndef _SUBTEXTURE_H_
#define _SUBTEXTURE_H_


namespace lite
{
    class Rect;
    class ITexture;

    class SubTextureSheet;

    class SubTexture
    {
        public:
        SubTexture(const SubTextureSheet* sheet, int index);

        const SubTextureSheet* sheet() const;
        int index() const;

        const ITexture* texture() const;
        const Rect& rect() const;

        protected:
        SubTextureSheet* _sheet;
        int _index;
        Rect _rect;
    };

} // namespace lite

#endif
