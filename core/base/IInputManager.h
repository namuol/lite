// TODO: DOCUMENTATION
// TODO: Decouple the keyboard stuff from the SDL code and move it here.
// An interface for an input manager.

#ifndef _IINPUTMANAGER_H_
#define _IINPUTMANAGER_H_

namespace fix
{
    class Button;
    class Mouse;

    class IInputManager
    {
        public:
        virtual void init() = 0;
        virtual void deinit() = 0;
        virtual const Button* button(int code) const = 0;
        virtual const Mouse& mouse() const = 0;

        virtual void update(int dt) = 0; 
    };
} // namespace fix
#endif
