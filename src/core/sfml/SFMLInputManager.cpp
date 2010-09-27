#include <SFML/Graphics.hpp>
using sf::Window;

#include <SFML/Window.hpp>

#include "ITimer.h"
#include "Button.h"
#include "Mouse.h"
#include "SFMLInputManager.h"
#include "SFMLKey.h"

#if 1
#include <iostream>
using namespace std;
#endif

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
        map<Key, string>::iterator ik;
        map<MouseButton, string>::iterator imb;

        sf::Event event;

        /* TODO
        int x, y;
        SFML_GetMouseState(&x, &y);
        _mouse.position(Vector2(x, y));
        */

        while( _window->GetEvent(event) ) {
            switch( event.Type )
            {
            case sf::Event::KeyPressed:
                ik = keys.find( keyFromCode(event.Key.Code) );
                if( ik != keys.end())
                {
                    press(buttons[ik->second]);
                }
                break;
            case sf::Event::KeyReleased:
                ik = keys.find( keyFromCode(event.Key.Code) );
                if( ik != keys.end())
                {
                    release(buttons[ik->second]);
                }
                break;
            case sf::Event::MouseMoved:
                break;
            case sf::Event::MouseButtonPressed:
                /* TODO
                imb = mouse_buttons.find(event.button.button);
                if( imb != mouse_buttons.end())
                {
                    buttons[imb->second]->last_pressed_time(current_time);
                }
                */
                break;
            case sf::Event::MouseButtonReleased:
                /* TODO
                imb = mouse_buttons.find(event.button.button);
                if( imb != mouse_buttons.end())
                {
                    buttons[imb->second]->last_released_time(current_time);
                }
                */
                break;
            default:
                break;
            }
        }
    }

} // namespace lite
