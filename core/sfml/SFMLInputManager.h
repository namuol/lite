// TODO: DOCUMENTATION
// An interface for an input manager.

#ifndef _SFMLINPUTMANAGER_H_
#define _SFMLINPUTMANAGER_H_

#include <map>
using std::map;

#include "IInputManager.h"

#include "Key.h"
#include "Mouse.h"

namespace fix
{
    class App;
    class Button;

    class SFMLInputManager : public IInputManager
    {
        public:
        SFMLInputManager(ITimer* timer);

        virtual void init();
        virtual void deinit();
        virtual const Button& button(const string name) const;
        virtual const Mouse& mouse() const;

        virtual void update(int dt);
        
        virtual void mapKey(Key k, const string name);
        virtual void mapMouseButton(MouseButton mb, const string name);

        private:
        ITimer* timer;

        map<int, Button*> buttons;

        map<SFMLKey, int> keys;
        map<Uint8, int> mouse_buttons;

        Mouse _mouse;
    };
} // namespace fix
#endif
