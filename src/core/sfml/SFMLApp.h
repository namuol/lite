// TODO: DOCUMENTATION
// The base class of all SFML games.

#ifndef _SFMLAPP_H_
#define _SFMLAPP_H_

#include "App.h"

namespace lite
{
    class SFMLDrawTarget;
    class SFMLTimer;
    class SFMLInputManager;
    class SFMLTextureLib;

    class SFMLApp : public App
    {
        
        public:
        SFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
            SFMLTextureLib* textures,
            bool fixedTimestep=true, int targetFPS=60);

        virtual ~SFMLApp();

        virtual void init();

        protected:
        virtual void update(int dt);
        virtual void deinit(); 
    };

} // namespace lite
#endif
