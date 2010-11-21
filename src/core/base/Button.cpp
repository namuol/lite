#include "ITimer.h"
#include "Button.h"

namespace lite
{
    Button::Button(ITimer* timer)
    : timer(timer)
    {
        // Important: we must have last_released_time > last_pressed_time
        //  in order to satisfy is_released(), since all buttons should
        //  start out in the released state.
        _last_pressed_time = -2;
        _last_released_time = -1;
    }

    Button::~Button()
    {
    }

    bool Button::is_pressed() const
    {
       return _last_pressed_time > _last_released_time;
    }

    bool Button::is_released() const
    {
       return _last_released_time > _last_pressed_time;
    }
    
    bool Button::was_just_pressed() const
    {
        return (_last_pressed_time >= 0 && 
                (timer->current_time() - _last_pressed_time) == 0 );
    }
    
    bool Button::was_just_released() const
    {
        return (_last_released_time >= 0 && 
                (timer->current_time() - _last_released_time) == 0 );
    }
    
    int Button::pressed_time() const
    {
        if( !is_pressed() || _last_pressed_time < 0 )
            return 0;
        return timer->current_time() - _last_pressed_time;
    }
    
    int Button::released_time() const
    {
        if( _last_released_time < 0 )
            return timer->current_time();
        return timer->current_time() - _last_released_time;       
    }

    int Button::last_pressed_time() const
    {
        return _last_pressed_time;
    }

    int Button::last_released_time() const
    {
        return _last_released_time;
    }

} // namespace lite
