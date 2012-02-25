#ifndef _SFMLKEY_H_
#define _SFMLKEY_H_

#include <map>
using std::map;

#include <SFML/Window.hpp>
using sf::Key::Code;
using namespace sf::Key;

#include "Key.h"

namespace lite
{
    Key keyFromCode(Code c);
} // namespace lite

#endif
