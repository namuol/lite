#include <iostream>
#include <cstdlib>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Vector3.h"

#include "App.h"
#include "Sprite.h"
#include "Button.h"
#include "Mouse.h"

#include "SFMLApp.h"
#include "SFMLDrawTarget.h"
#include "SFMLTimer.h"
#include "SFMLInputManager.h"

using namespace lite;

class TestSFMLApp : public SFMLApp
{
    public:
    TestSFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
        bool fixedTimestep=true, int targetFPS=60):
    SFMLApp(drawTarget, timer, input, fixedTimestep, targetFPS)
    {
        img.LoadFromFile("wut.png");
        tex = new SFMLTexture(&img);
        sprite = new Sprite(_drawTarget,tex);
        _drawTarget->add_drawable(sprite);

        input->mapKey(K_ESCAPE, "quit");
        input->mapKey(K_q, "quit_hold");
    }

    virtual ~TestSFMLApp()
    {
        delete sprite;
        delete tex;
    }

    protected:
    sf::Image img;
    SFMLTexture* tex;
    Sprite* sprite;

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
