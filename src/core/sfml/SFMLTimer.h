// TODO: DOCUMENTATION
// A timer via SFML.

#ifndef _SFMLTIMER_H_
#define _SFMLTIMER_H_

#include <SFML/System.hpp>
using sf::Clock;

#include "ITimer.h"

namespace lite
{
    class SFMLTimer : public ITimer
    {
        public:
        virtual void init();
        virtual void deinit();
        
        virtual void lazy_wait(int ms);

        private:
        virtual int get_time();
        Clock clock;
    };
} // namespace lite
#endif
