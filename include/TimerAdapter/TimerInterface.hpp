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
    milliseconds GetTicks()
    {
        return this->GetImplemetation()->GetTicks();
    }

    void Delay(milliseconds ms)
    {
        this->GetImplemetation()->Delay(ms);
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
