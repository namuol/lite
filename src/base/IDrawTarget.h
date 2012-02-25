// TODO: DOCUMENTATION
// An interface for a surface to draw on.

#ifndef _IDRAWTARGET_H_
#define _IDRAWTARGET_H_
#include <list>
using std::list;

#include "Color.h"

#include "ITexture.h"

namespace lite
{
    namespace Filter {
        enum Mode {
            NEAREST,
            LINEAR
        };
    }

    namespace Blend
    {
        enum Mode
        {
            ALPHA,
            ADD,
            MULT,
            NONE
        };
    }

    class IDrawable;

    bool compare_draworder(IDrawable* first, IDrawable* second);

    class IDrawTarget
    {
        public:
        IDrawTarget();

        IDrawTarget(unsigned int width, unsigned int height,
                    const Color& clearColor=Color());

        virtual ~IDrawTarget();

        virtual void init() = 0;
        virtual void deinit() = 0;

        // I really would prefer that this be pure-virtual, but I cannot call
        //  drawTexture in the base Sprite class otherwise.
        virtual void drawTexture(const lite::ITexture* tex,
                                 float x=0.f, float y=0.f,
                                 float scalex=1.f, float scaley=1.f,
                                 float rotation=0.f,
                                 const Color& rgba=Color::WHITE,
                                 Blend::Mode mode=Blend::ALPHA) = 0;

        virtual void clear() = 0;

        virtual void draw(int dt);

        virtual void add_drawable(IDrawable* drawable);
        virtual void rem_drawable(IDrawable* drawable);
        virtual void sort_drawables();

        unsigned int width() const;
        unsigned int height() const;

        void filterMode(Filter::Mode filterMode);
        Filter::Mode filterMode() const;
        
        void clearColor(const Color& val);
        const Color& clearColor() const;

        protected:
        virtual void _filterModeChanged() = 0;

        list<IDrawable*> drawables;
        unsigned int _width, _height;

        private:
        Color _clearColor;
        Filter::Mode _filterMode;
    };
} // namespace lite
#endif
