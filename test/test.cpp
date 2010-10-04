#include <iostream>
#include <cstdlib>
using namespace std;

#include <string>
using std::string;

#include <SFML/Graphics.hpp>

#include "Vector2.h"

#include "App.h"
#include "IUpdateable.h"
#include "Sprite.h"
#include "Button.h"
#include "Mouse.h"

#include "SFMLApp.h"
#include "SFMLDrawTarget.h"
#include "SFMLTimer.h"
#include "SFMLInputManager.h"
#include "SFMLTextureLib.h"

#include "Rect.h"

IntRect test;

using namespace lite;

static const Vector2 GRAVITY(0.0, 0.3);
static const float BOUNCE_ELASTICITY = 0.85;
static const float FRICTION = 0.9;

class BouncySprite : public Sprite, public IUpdateable
{
    public:
    BouncySprite(App* app, const ITexture* tex,
                 const Vector2& position=Vector2(),
                 const Vector2& velocity=Vector2()):
        Sprite(app->drawTarget(),
               tex,
               0.f,
               position),
        IUpdateable(app),
        _velocity(velocity)
    {
    }

    virtual void update(int dt)
    {
        _velocity += GRAVITY;
        _position += _velocity;
    
        if( (_position.x + width()) > drawTarget->height() )
        {
            _position.x = drawTarget->width() - width();
            _velocity.x *= -BOUNCE_ELASTICITY;
            _velocity.y *= FRICTION;
        }
        else if( _position.x < 0 )
        {
            _position.x = 0;
            _velocity.x *= -BOUNCE_ELASTICITY;
            _velocity.y *= FRICTION;
        }

        if( (_position.y + height()) > drawTarget->height() )
        {
            _position.y = drawTarget->height() - height();
            _velocity.y *= -BOUNCE_ELASTICITY;
            _velocity.x *= FRICTION;
        }
        else if( _position.y < 0 )
        {
            _position.y = 0;
            _velocity.y *= -BOUNCE_ELASTICITY;
            _velocity.x *= FRICTION;
        }
    }

    private:
    Vector2 _velocity;
};

class TestSFMLApp : public SFMLApp
{
    public:
    TestSFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
        bool fixedTimestep=true, int targetFPS=60):
    SFMLApp(drawTarget, timer, input, fixedTimestep, targetFPS)
    {
        textures.load("wut.png");
        sprite = new BouncySprite(this,textures["wut.png"]);
        sprite->scaley(1.f);
        sprite->scalex(1.f);
        _drawTarget->add_drawable(sprite);
        add_updateable(sprite);

        input->mapKey(K_ESCAPE, "quit");
        input->mapKey(K_q, "quit_hold");
    }

    virtual ~TestSFMLApp()
    {
        delete sprite;
    }

    protected:
    sf::Image img;
    BouncySprite* sprite;

    virtual void update(int dt)
    {
        SFMLApp::update(dt);
        if( _input->button("quit").was_just_pressed() ||
            _input->button("quit_hold").pressed_time() > 2000 )
        {
            running = false;
        }
    }
};

int main(int ac, char **av)
{
    sf::RenderWindow window(sf::VideoMode(640,480), "Testing lite via SFML");
    
    SFMLDrawTarget drawTarget(&window);
    SFMLTimer timer;
    SFMLInputManager input(&timer, &window);
    
    TestSFMLApp testApp(&drawTarget, &timer, &input);
    
    testApp.init();
    testApp.run();

    return 0;
}
