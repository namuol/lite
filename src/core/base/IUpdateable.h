// TODO: DOCUMENTATION
// An interface for anything in the game that can be updated.

#ifndef _IUPDATEABLE_H_
#define _IUPDATEABLE_H_

namespace lite
{
    class App;

    class IUpdateable
    {
        public:
        IUpdateable();
        IUpdateable(App* app);

        virtual ~IUpdateable();

        virtual void update(int dt) = 0;
        
        virtual float get_updateorder() const;

        virtual void set_updateorder(float updateorder);
        
        protected:
        App* app;

        float updateorder;
    };
} // namespace lite

#endif
