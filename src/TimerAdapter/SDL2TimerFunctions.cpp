#include <SDL2TimerFunctions.hpp>

namespace SDL2Timer
{

void Init()
{
    return;
}

milliseconds GetTicks()
{
    return SDL_GetTicks();
}

void Delay(milliseconds ms)
{
    SDL_Delay(ms);
}

void Quit()
{
    return;
}

} /* namespace SDL2Timer */