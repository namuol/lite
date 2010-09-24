#include <SFML/Clock.hpp>
using sf::Clock;
#include <SFML/Sleep.hpp>
using sf::Sleep;

#include "SFMLTimer.h"

namespace fix
{
    void SFMLTimer::init()
    {
        clock.Reset();
    }

    void SFMLTimer::deinit()
    {
    }

    int SFMLTimer::get_time()
    {
        return static_cast<int>(clock.GetElapsedTime()*1000.0 + 0.5);
    }

    void SFMLTimer::lazy_wait(int ms)
    {
        Sleep((static_cast<float>ms)/1000.0); 
    }
} // namespace fix
