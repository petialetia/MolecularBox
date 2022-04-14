#ifndef TIMER_INTERFACE_HPP
#define TIMER_INTERFACE_HPP

#include "UsingAliasTimer.hpp"

template<typename Implementation>
class TimerInterface
{
  protected:
    TimerInterface() = default;

  private:
    void Init()
    {
        this->GetImplemetation()->Init();
    }

  public:
    void Delay(milliseconds ms)
    {
        this->GetImplementation()->Delay();
    }

  private:
    void Quit()
    {
        this->GetImplemetation()->Quit();
    }
    
    Implementation* GetImplemetation()
    {
        return static_cast<Implementation*>(this);
    }
};

#endif /* TIMER_INTERFACE_HPP */
