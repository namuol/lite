#ifndef _SFMLDRAWTARGET_H_
#define _SFMLDRAWTARGET_H_

#include <list>
using std::list;

#include <SFML/RenderTarget.h>

#include "IDrawTarget.h"

namespace lite
{
    class IDrawable;

    class SFMLDrawTarget : public IDrawTarget
    {
        public:
        SFMLDrawTarget(RenderTarget* screen);
        virtual void init();
        virtual void deinit();

        RenderTarget* screen() const;

        private:
        RenderTarget* _screen;
    };
} // namespace lite
#endif
