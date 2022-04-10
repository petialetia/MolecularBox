#ifndef TIMER_INTERFACE_HPP
#define TIMER_INTERFACE_HPP

#include "UsingAliasTimer.hpp"

template<typename Implementation>
class TimerInterface
{
  public:
    TimerInterface() = default;

    void Init()
    {
        this->GetImplemetation()->Init();
    }

    void Delay(milliseconds ms)
    {
        this->GetImplementation()->Delay();
    }

    void Quit()
    {
        this->GetImplemetation()->Quit();
    }

  private:
    Implementation* GetImplemetation()
    {
        return static_cast<Implementation*>(this);
    }
};

#endif /* TIMER_INTERFACE_HPP */
