// TODO: DOCUMENTATION
// NOTE: This class is quite meaningless without an InputManager to go along with it.
// A Button object doesn't contain information about which actual physical button or key
//  or whatever is associated with it, it's just used internally to make it simpler to 
//  implement an InputManager module.

#ifndef _BUTTON_H_
#define _BUTTON_H_
#include "IInputManager.h"

namespace lite
{
    class ITimer;
    
    class Button
    {
        public:
        Button(ITimer* timer);

        virtual ~Button();

        virtual bool is_pressed() const;
        virtual bool is_released() const;
        virtual bool was_just_pressed() const;
        virtual bool was_just_released() const;
        virtual int pressed_time() const;
        virtual int released_time() const;
        
        int last_pressed_time() const;
        int last_released_time() const;

        protected:
        friend void IInputManager::press(Button* b) const;
        friend void IInputManager::release(Button* b) const;

        private:
        ITimer* timer;
        int _last_pressed_time;
        int _last_released_time; 

    };
} // namespace lite
#endif
