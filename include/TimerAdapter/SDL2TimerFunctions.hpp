#ifndef SDL2_TIMER_FUNCTIONS_HPP
#define SDL2_TIMER_FUNCTIONS_HPP

#include <SDL2/SDL.h>

#include "UsingAliasTimer.hpp"

namespace SDL2Timer
{

void Init();

milliseconds GetTicks();

void Delay(milliseconds ms);

void Quit();

} /* namespace SDL2Timer */

#endif /* SDL2_TIMER_FUNCTIONS_HPP */
