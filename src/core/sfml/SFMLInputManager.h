// TODO: DOCUMENTATION
// An interface for an input manager.

#ifndef _SFMLINPUTMANAGER_H_
#define _SFMLINPUTMANAGER_H_

#include <SFML/Graphics.hpp>
using sf::Window;

#include <map>
using std::map;

#include "IInputManager.h"

#include "Key.h"
#include "Mouse.h"

namespace lite
{
    class App;
    class Button;

    class SFMLInputManager : public IInputManager
    {
        public:
        SFMLInputManager(ITimer* timer, Window* window);

        virtual void init();
        virtual void deinit();

        virtual void update(int dt);
        
        virtual void mapKey(Key k, const string& name);
        virtual void mapMouseButton(MouseButton mb, const string& name);

        private:
        Window* _window;
    };
} // namespace lite
#endif
