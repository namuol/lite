// TODO: DOCUMENTATION
// An interface for anything in the game that can be rendered.

#ifndef _IDRAWABLE_H_
#define _IDRAWABLE_H_
namespace lite
{
    class IDrawable
    {
        public:
        IDrawable(IDrawTarget* target, float drawOrder);

        virtual float drawOrder() const;
        virtual void drawOrder(float drawOrder) const;

        virtual void draw(int dt) const = 0;

        private:
        float _drawOrder;
        IDrawTarget* drawTarget;

    };
} // namespace lite
#endif
