#ifndef _ITILEMAP_H_
#define _ITILEMAP_H_

namespace lite
{
    class Tile;

    class ITileMap
    {
        public:
        virtual unsigned int width() const = 0;
        virtual unsigned int height() const = 0;

        virtual unsigned int tileWidth() const = 0;
        virtual void tileWidth(unsigned int val) = 0;

        virtual unsigned int tileHeight() const = 0;
        virtual void tileHeight(unsigned int val) = 0;

        virtual unsigned int layerCount() const = 0;
        virtual unsigned int subLayerCount() const = 0;

        virtual Tile* get(int x, int y) const = 0;

        virtual void set(int x, int y, const Tile& t) = 0;
        virtual void clear(int x, int y) = 0;
    };


} // namespace lite

#endif
