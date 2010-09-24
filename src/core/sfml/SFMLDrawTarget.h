#ifndef _SFMLDRAWTARGET_H_
#define _SFMLDRAWTARGET_H_

#include <list>
using std::list;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "IDrawTarget.h"

namespace lite
{
    class IDrawable;

    class SFMLDrawTarget : public IDrawTarget
    {
        public:
        SFMLDrawTarget(RenderWindow* window);
        virtual void init();
        virtual void deinit();

        virtual void draw(int dt);

        private:
        RenderWindow* _window;
    };
} // namespace lite
#endif
