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
                       const Color& clearColor=Color(),
                       const string& title="");
        SFMLDrawTarget(RenderWindow* window, const Color& clearColor=Color());
        virtual void init();
        virtual void deinit();

        virtual void draw(int dt);
        virtual void drawTexture(const lite::ITexture* tex, float x, float y,
                                 float scalex=1.0, float scaley=1.0,
                                 float rotation=0.0,
                                 const Color& rgba=Color::WHITE,
                                 Blend::Mode mode=Blend::ALPHA);
        virtual void clear();

        RenderWindow* window() { return _window; }
        
        protected:
        virtual void _filterModeChanged();

        private:
        RenderWindow* _window;
    };
} // namespace lite
#endif
