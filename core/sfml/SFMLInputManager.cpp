#include "SFML.h"

#define _DEBUG_SFML_INPUT
#ifdef _DEBUG_SFML_INPUT
#include <iostream>
using namespace std;
#endif

#include "ITimer.h"
#include "Button.h"
#include "Mouse.h"
#include "SFMLInputManager.h"

namespace fix
{
    SFMLInputManager::SFMLInputManager(ITimer* timer)
    : timer(timer)
    {
    }

    void SFMLInputManager::init()
    {
        // TODO: add joystick support..
        // TODO: add mouse support..
    }
    
    void SFMLInputManager::deinit()
    {
    }

    const Button* SFMLInputManager::button(int code) const
    {
        Button* button;
        map<int, Button*>::const_iterator ib;

        ib = buttons.find(code);
        
        if( ib == buttons.end() )
        {
            button = NULL;
        }
        else
        {
            button = (*ib).second;
        }

        return button;
    }

    const Mouse& SFMLInputManager::mouse() const
    {
        return _mouse;
    }

    void SFMLInputManager::map_key(SFMLKey key, int code)
    {
        map<int, Button*>::iterator ib;

        ib = buttons.find(code);
        if( ib == buttons.end() )
        {
            Button* button = new Button(timer);
            buttons[code] = button;
        }
        keys[key] = code;
    }

    void SFMLInputManager::map_mouse_button(Uint8 mouse_button, int code)
    {
        map<int, Button*>::iterator ib;

        ib = buttons.find(code);
        if( ib == buttons.end() )
        {
            Button* button = new Button(timer);
            buttons[code] = button;
        }
        mouse_buttons[mouse_button] = code;
    }

    void SFMLInputManager::update(int dt)
    {
        int current_time = timer->current_time();
        map<SFMLKey, int>::iterator ik;
        map<Uint8, int>::iterator imb;

        SFML_Event event;

        int x, y;
        SFML_GetMouseState(&x, &y);
        _mouse.position(Vector2(x, y));

        while( SFML_PollEvent( &event ) ) {
            switch( event.type )
            {
            case SFML_KEYDOWN:
                ik = keys.find(event.key.keysym.sym);
                if( ik != keys.end())
                {
                    buttons[ik->second]->last_pressed_time(current_time);
                }
                break;
            case SFML_KEYUP:
                ik = keys.find(event.key.keysym.sym);
                if( ik != keys.end())
                {
                    buttons[ik->second]->last_released_time(current_time);
                }
                break;
            case SFML_MOUSEMOTION:
                break;
            case SFML_MOUSEBUTTONDOWN:
                imb = mouse_buttons.find(event.button.button);
                if( imb != mouse_buttons.end())
                {
                    buttons[imb->second]->last_pressed_time(current_time);
                }
                break;
            case SFML_MOUSEBUTTONUP:
                imb = mouse_buttons.find(event.button.button);
                if( imb != mouse_buttons.end())
                {
                    buttons[imb->second]->last_released_time(current_time);
                }
                break;
            }
        }
    }

} // namespace fix
