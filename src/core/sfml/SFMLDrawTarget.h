#ifndef _SFMLDRAWTARGET_H_
#define _SFMLDRAWTARGET_H_

#include <string>
using std::string;

#include <list>
using std::list;

#include <SFML/Graphics.hpp>
using sf::RenderWindow;

#include "IDrawTarget.h"
#include "SFMLTexture.h"

namespace lite
{
    class SFMLDrawTarget : public IDrawTarget
    {
        public:
        SFMLDrawTarget(unsigned int width, unsigned int height,
                        const string& title="");
        SFMLDrawTarget(RenderWindow* window);
        virtual void init();
        virtual void deinit();

        virtual void draw(int dt);
        virtual void drawTexture(const lite::ITexture* tex, float x, float y,
                                 float scalex=1.0, float scaley=1.0,
                                 float rotation=0.0, Blend::Mode mode=Blend::ALPHA);

        RenderWindow* window() { return _window; }

        private:
        RenderWindow* _window;
    };
} // namespace lite
#endif
