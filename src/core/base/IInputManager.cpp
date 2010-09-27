#include "ITimer.h"
#include "Button.h"
#include "Mouse.h"
#include "IInputManager.h"

namespace lite
{
    IInputManager::IInputManager(ITimer* timer)
    : timer(timer)
    {
    }

    const Button&
    IInputManager::button(const string& name) const
    {
        Button* button;
        map<string, Button*>::const_iterator ib;

        ib = buttons.find(name);
        
        if( ib == buttons.end() )
        {
            button = NULL;
        }
        else
        {
            button = (*ib).second;
        }

        return *button;
    }

    const Mouse&
    IInputManager::mouse() const
    {
        return _mouse;
    }

    void
    IInputManager::mapKey(Key k, const string& name)
    {
        map<string, Button*>::iterator ib;

        ib = buttons.find(name);
        if( ib == buttons.end() )
        {
            Button* button = new Button(timer);
            buttons[name] = button;
        }
        keys[k] = name;
    }

    void
    IInputManager::mapMouseButton(MouseButton mb, const string& name)
    {
        map<string, Button*>::iterator ib;

        ib = buttons.find(name);
        if( ib == buttons.end() )
        {
            Button* button = new Button(timer);
            buttons[name] = button;
        }
        mouse_buttons[mb] = name;
    }

    void
    IInputManager::press(Button* b) const
    {
        b->_last_pressed_time = timer->current_time();
    }

    void
    IInputManager::release(Button* b) const
    {
        b->_last_released_time = timer->current_time();
    }


} // namespace lite
