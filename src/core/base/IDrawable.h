// TODO: DOCUMENTATION
// An interface for anything in the game that can be rendered.

#ifndef _IDRAWABLE_H_
#define _IDRAWABLE_H_
namespace lite
{
    class IDrawTarget;

    class IDrawable
    {
        public:
        IDrawable(IDrawTarget* target, float drawOrder);
        virtual ~IDrawable();

        virtual float drawOrder() const;
        virtual void drawOrder(float drawOrder);

        virtual void draw(int dt) const = 0;

        private:
        IDrawTarget* drawTarget;
        float _drawOrder;
    };
} // namespace lite
#endif
