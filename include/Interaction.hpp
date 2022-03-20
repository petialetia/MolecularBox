#include <functional>

class Predictable {};
class Continuus {};

template <typename Tag>
class Interaction
{
  private:

    std::function<void()> Action_ = []() { return; };
    std::function<time_type()> GetTimeToNextInteraction_ = []() { return 0; };
    
  public:

    explicit Interaction(std::function<void()> Action, std::function<time_type()> GetTimeToNextInteraction) : 
    Action_(Action), GetTimeToNextInteraction_(GetTimeToNextInteraction) 
    {
    }

    void Action()
    {
        Action_();
    }

    time_type GetTimeToNextInteraction()
    {
        return GetTimeToNextInteraction_();
    }   
};