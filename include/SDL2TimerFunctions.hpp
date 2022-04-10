#ifndef SDL2_TIMER_FUNCTIONS_HPP
#define SDL2_TIMER_FUNCTIONS_HPP

#include <SDL2/SDL.h>

#include <include/UsingAliasTimer.hpp>

namespace SDL2Timer
{

void Init();

void Delay(milliseconds ms);

void Quit();

} /* namespace SDL2 */

#endif /* SDL2_TIMER_FUNCTIONS_HPP */
