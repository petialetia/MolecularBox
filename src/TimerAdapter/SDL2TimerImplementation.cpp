#include <SDL2TimerImplementation.hpp>

SDL2TimerImplementation::SDL2TimerImplementation(Init_type Init, GetTicks_type GetTicks, Delay_type Delay, Quit_type Quit) :
    Init_(Init), GetTicks_(GetTicks), Delay_(Delay), Quit_(Quit)
{
    Init();
}

void SDL2TimerImplementation::Init() const
{
    Init_();
}

milliseconds SDL2TimerImplementation::GetTicks() const
{
    return GetTicks_();
}

void SDL2TimerImplementation::Delay(milliseconds ms) const
{
    Delay_(ms);
}

void SDL2TimerImplementation::Quit() const
{
    Quit_();
}

SDL2TimerImplementation::~SDL2TimerImplementation()
{
    Quit();
}

SDL2TimerImplementation GetSDL2TimerImplementation()
{
    return SDL2TimerImplementation(SDL2Timer::Init, SDL2Timer::GetTicks, SDL2Timer::Delay, SDL2Timer::Quit);
}