#include <iostream>
#include <cstdlib>
using namespace std;

#include <SFML/Graphics.hpp>

#include "Vector2.h"
#include "Vector3.h"

#include "App.h"
#include "SFMLApp.h"
#include "SFMLDrawTarget.h"
#include "SFMLTimer.h"
#include "SFMLInputManager.h"
#include "Button.h"
#include "Mouse.h"

using namespace lite;

class TestSFMLApp : public SFMLApp
{
    public:
    TestSFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
        bool fixedTimestep=true, int targetFPS=60):
    SFMLApp(drawTarget, timer, input, fixedTimestep, targetFPS)
    {
    }

    protected:
    virtual void update(int dt)
    {
        static int last_time = 0;
        int time = _timer->get_time();

        if(time > 5000)
            running = false;

        if(time/1000 > last_time)
        {
            last_time = time/1000;
            cout << last_time << endl;
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
