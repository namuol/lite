// TODO: DOCUMENTATION
// An interface for an input manager.

#ifndef _SFMLINPUTMANAGER_H_
#define _SFMLINPUTMANAGER_H_

#include <SFML/Graphics.hpp>

#include <map>
using std::map;

#include "IInputManager.h"

#include "Key.h"
#include "Mouse.h"

namespace lite
{
    class App;
    class Button;
    class SFMLDrawTarget;

    class SFMLInputManager : public IInputManager
    {
        public:
        SFMLInputManager(ITimer* timer, SFMLDrawTarget* drawTarget);
        SFMLInputManager(ITimer* timer, sf::Window* window);

        virtual void init();
        virtual void deinit();

        virtual void update(int dt);
        
        private:
        sf::Window* _window;
    };
} // namespace lite
#endif
