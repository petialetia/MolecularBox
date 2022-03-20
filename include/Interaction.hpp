#include <functional>

#include "UsingAlias.hpp"

class Predictable {};
class Continuus {};

template <typename Tag>
class Interaction
{
  private:

    std::function<void()> Action_ = []() { return; };
    std::function<time_type()> GetTimeToNextAction_ = []() { return 0; };
    
  public:

    explicit Interaction(std::function<void()> Action, std::function<time_type()> GetTimeToNextAction) : 
    Action_(Action), GetTimeToNextAction_(GetTimeToNextAction) 
    {
    }

    void Action()
    {
        Action_();
    }

    time_type GetTimeToNextAction()
    {
        return GetTimeToNextAction_();
    }   
};