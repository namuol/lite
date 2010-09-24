#include <SFML/Graphics.hpp>
using sf::Window;

#include "ITimer.h"
#include "Button.h"
#include "Mouse.h"
#include "SFMLInputManager.h"

namespace lite
{
    SFMLInputManager::SFMLInputManager(ITimer* timer, Window* window)
    : IInputManager(timer), _window(window)
    {
    }

    void SFMLInputManager::init()
    {
    }
    
    void SFMLInputManager::deinit()
    {
    }

    void SFMLInputManager::update(int dt)
    {
        /*
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
        */// TODO!
    }

    void
    SFMLInputManager::mapKey(Key k, const string& name)
    {
        // TODO
    }

    void
    SFMLInputManager::mapMouseButton(MouseButton mb, const string& name)
    {
        // TODO
    }

} // namespace lite
