// TODO: DOCUMENTATION
// An interface for anything in the game that can be updated.

#ifndef _IUPDATEABLE_H_
#define _IUPDATEABLE_H_

#include "App.h"

namespace lite
{
    class IUpdateable
    {
        public:
        IUpdateable(App* app)
        : app(app), updateorder(0.0f)
        {
        }

        ~IUpdateable()
        {
            app->rem_updateable(this);
        }

        virtual void update(int dt) = 0;
        
        virtual float get_updateorder() const
        {
            return updateorder;
        }

        virtual void set_updateorder(float updateorder)
        {
            app->sort_updateables();
        }
        
        protected:
        App* app;

        float updateorder;
    };
} // namespace lite
#endif
