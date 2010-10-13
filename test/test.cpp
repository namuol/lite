#include <iostream>
#include <cstdlib>
#include <ctime>
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

#include "TextureSheet.h"

#include "SFMLApp.h"
#include "SFMLDrawTarget.h"
#include "SFMLTimer.h"
#include "SFMLInputManager.h"
#include "SFMLTextureLib.h"

#include "Rect.h"
using namespace lite;

IntRect test;

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
        texgrid = TextureGrid(textures["wut.png"], 8, 8);
        sprite = new BouncySprite(this,texgrid[3]);
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
    TextureGrid texgrid;
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

#include "Camera.h"
#include "Tile.h"
#include "TileMap.h"
#include "TileMapLayer.h"

class TestTileModule : public SFMLApp
{
    static const unsigned int
        TM_WIDTH = 100,
        TM_HEIGHT = 100,
        TILE_WIDTH = 16,
        TILE_HEIGHT = 16,
        LAYER_COUNT = 2,
        SUBLAYER_COUNT = 2
    ;

    #define CAM_SPEED -5.0f

    public:
    TestTileModule(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
            bool fixedTimestep=true, int targetFPS=60):
        SFMLApp(drawTarget, timer, input, fixedTimestep, targetFPS),
        cam(Vector2(0,0),640,480)
    {
        textures.load("hell.png");
        texgrid = TextureGrid(textures["hell.png"], TILE_WIDTH, TILE_HEIGHT);

        input->mapKey(K_ESCAPE, "quit");

        input->mapKey(K_LEFT, "left");
        input->mapKey(K_RIGHT, "right");
        input->mapKey(K_UP, "up");
        input->mapKey(K_DOWN, "down");

        tileMap = new TileMap(TM_WIDTH, TM_HEIGHT, 
                              TILE_WIDTH, TILE_HEIGHT,
                              LAYER_COUNT, SUBLAYER_COUNT);

        front = new TileMapLayer(_drawTarget, *tileMap, cam, 0, 0.f);
        back = new TileMapLayer(_drawTarget, *tileMap, cam, 1, 1.f);

    }

    void init()
    {
        SFMLApp::init();

        srand( time(NULL) );

        // Generate tilemap here
        vector<vector<const ITexture*> > textures(
            LAYER_COUNT, vector<const ITexture*>( SUBLAYER_COUNT )
        );

        for(unsigned int x=0; x < TM_WIDTH; ++x)
        {
            for(unsigned int y=0; y< TM_HEIGHT; ++y)
            {
                for(unsigned int i=0; i < LAYER_COUNT; ++i)
                    for(unsigned int j=0; j < SUBLAYER_COUNT; ++j)
                        textures[i][j] = texgrid[rand() % texgrid.size()];
                tileMap->set(x,y, Tile(textures));
            }
        }
        
        // Add our tilemap layers for rendering:
        _drawTarget->add_drawable(front);
        _drawTarget->add_drawable(back);
    }

    virtual ~TestTileModule()
    {
        delete tileMap;
    }

    protected:
    // Text texturegrid:
    TextureGrid texgrid;
    Camera cam;
    TileMap* tileMap;
    TileMapLayer* front;
    TileMapLayer* back;

    virtual void update(int dt)
    {
        SFMLApp::update(dt);

        if( _input->button("quit").was_just_pressed() )
        {
            running = false;
        }

        Vector2 cam_velocity;
        if( _input->button("left").is_pressed() )
            cam_velocity.x = CAM_SPEED;
        else if( _input->button("right").is_pressed() )
            cam_velocity.x = -CAM_SPEED;

        if( _input->button("up").is_pressed() )
            cam_velocity.y = CAM_SPEED;
        else if( _input->button("down").is_pressed() )
            cam_velocity.y = -CAM_SPEED;
            
        cam.position(cam.realPosition() + cam_velocity);
    }

};

int main(int ac, char **av)
{
    sf::RenderWindow window(sf::VideoMode(640,480), "Testing lite via SFML");
    
    SFMLDrawTarget drawTarget(&window);
    SFMLTimer timer;
    SFMLInputManager input(&timer, &window);
    
    //TestSFMLApp testApp(&drawTarget, &timer, &input);
    TestTileModule testApp(&drawTarget, &timer, &input);
    
    testApp.init();
    testApp.run();

    return 0;
}
