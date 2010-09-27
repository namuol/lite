// TODO: DOCUMENTATION
// TODO: Decouple the keyboard stuff from the SDL code and move it here.
// An interface for an input manager.

#ifndef _IINPUTMANAGER_H_
#define _IINPUTMANAGER_H_
#include <map>
using std::map;

#include <string>
using std::string;

#include "Mouse.h"
#include "Key.h"

namespace lite
{
    class Button;

    class IInputManager
    {
        public:

        virtual void init() = 0;
        virtual void deinit() = 0;
        
        virtual void update(int dt) = 0; 

        IInputManager(ITimer* timer);

        const Button& button(const string& name) const;
        const Mouse& mouse() const;
        void mapKey(Key k, const string& name);
        void mapMouseButton(MouseButton mb, const string& name);

        protected:
        friend class Button;
        void press(Button* b) const;
        void release(Button* b) const;

        map<string, Button*> buttons;

        ITimer* timer;

        map<Key, string> keys;
        map<MouseButton, string> mouse_buttons;

        Mouse _mouse;
    };
} // namespace lite
#endif
