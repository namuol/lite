// TODO: DOCUMENTATION
// An interface for anything in the game that can be rendered.

#ifndef _IDRAWABLE_H_
#define _IDRAWABLE_H_
namespace lite
{
    class IDrawable : IHasZ
    {
        public:
        virtual void draw(int dt) const = 0;
    };
} // namespace lite
#endif
