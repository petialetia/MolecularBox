#include <include/SDL2TimerFunctions.hpp>

namespace SDL2Timer
{

void Init()
{
    return;
}

void Delay(milliseconds ms)
{
    SDL_Delay(ms);
}

void Quit()
{
    return;
}

} /* namespace SDL2 */