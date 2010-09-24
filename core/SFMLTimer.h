// TODO: DOCUMENTATION
// A timer via SDL.

#ifndef _SDLTIMER_H_
#define _SDLTIMER_H_

#include <SFML/Clock.hpp>

#include "ITimer.h"

namespace fix
{
    class SDLTimer : public ITimer
    {
        public:
        virtual void init();
        virtual void deinit();
        
        virtual void lazy_wait(int ms);

        private:
        virtual int get_time();
        Clock clock;
    };
} // namespace fix
#endif
