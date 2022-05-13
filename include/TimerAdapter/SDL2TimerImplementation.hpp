#ifndef SDL2_TIMER_IMPLEMENTATION_HPP
#define SDL2_TIMER_IMPLEMENTATION_HPP

#include <SDL2/SDL.h>

#include "TimerInterface.hpp"
#include "SDL2TimerFunctions.hpp"

#include <functional>

using Init_type =     std::function<void()>;
using GetTicks_type = std::function<milliseconds()>;
using Delay_type =    std::function<void(milliseconds)>;
using Quit_type =     std::function<void()>;

class SDL2TimerImplementation : public TimerInterface<SDL2TimerImplementation>
{
  private:
    Init_type Init_;
    GetTicks_type GetTicks_;
    Delay_type Delay_;
    Quit_type Quit_;

  public:
    SDL2TimerImplementation() = delete;
    SDL2TimerImplementation(Init_type Init, GetTicks_type GetTicks, Delay_type Delay, Quit_type Quit);

    void Init() const;
    milliseconds GetTicks() const;
    void Delay(milliseconds ms) const;
    void Quit() const;

    ~SDL2TimerImplementation();
};

SDL2TimerImplementation GetSDL2TimerImplementation();

#endif /* SDL2_TIMER_IMPLEMENTATION_HPP */
