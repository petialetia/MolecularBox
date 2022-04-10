#ifndef SDL2_TIMER_IMPLEMENTATION_HPP
#define SDL2_TIMER_IMPLEMENTATION_HPP

#include <SDL2/SDL.h>

#include "TimerInterface.hpp"

#include <functional>

using Init_type =  std::function<void()>;
using Delay_type = std::function<void(milliseconds)>;
using Quit_type =  std::function<void()>;

class SDL2TimerImplementation : public TimerInterface<SDL2TimerImplementation>
{
  private:

    Init_type Init_;
    Delay_type Delay_;
    Quit_type Quit_;

  public:
    SDL2TimerImplementation() = delete;

    SDL2TimerImplementation(Init_type Init, Delay_type Delay, Quit_type Quit);

    void Init() const;
    void Delay(milliseconds ms) const;
    void Quit() const;

    ~SDL2TimerImplementation();
};

#endif /* SDL2_TIMER_IMPLEMENTATION_HPP */
