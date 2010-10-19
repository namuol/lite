// TODO: DOCUMENTATION
// The base class of all SFML games.

#ifndef _SFMLAPP_H_
#define _SFMLAPP_H_

#include "SFMLTextureLib.h"
#include "App.h"

namespace lite
{
    class SFMLDrawTarget;
    class SFMLTimer;
    class SFMLInputManager;

    class SFMLApp : public App
    {
        
        public:
        SFMLApp(SFMLDrawTarget* drawTarget, SFMLTimer* timer, SFMLInputManager* input, 
            bool fixedTimestep=true, int targetFPS=60);

        virtual ~SFMLApp();

        virtual void init();

        virtual void update(int dt);

        protected:
        virtual void deinit(); 
    };

} // namespace lite
#endif
