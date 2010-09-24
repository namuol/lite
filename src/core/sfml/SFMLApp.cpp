#include <SFML/Graphics.hpp>

#include "App.h"
#include "SFMLApp.h"
#include "SFMLTimer.h"
#include "SFMLDrawTarget.h"
#include "SFMLInputManager.h"
//#include "SFMLTextureLib.h"

namespace lite
{
    // Public methods:
    SFMLApp::SFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
            bool fixedTimestep, int targetFPS)
    : App(drawTarget, timer, input, fixedTimestep, targetFPS)
    {
    }

    SFMLApp::~SFMLApp()
    {
    }

    void
    SFMLApp::init()
    {
        App::init();
    }

    // Protected methods:
    void
    SFMLApp::update(int dt)
    {
        App::update(dt);
    }

    void
    SFMLApp::deinit()
    {
        App::deinit();
        //texLib.unload_all_textures();
    }
} // namespace lite
