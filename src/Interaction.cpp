#include <include/Interaction.hpp>

Interaction::Interaction(std::function<void()> Action, std::function<bool()> CheckConditionForAction) : 
    Action_(Action), CheckConditionForAction_(CheckConditionForAction)
{
}

void Interaction::Action() const
{
    Action_();
}

bool Interaction::CheckConditionForAction() const
{
    return CheckConditionForAction_();
}

PredictableInteraction::PredictableInteraction(std::function<void()> Action, std::function<time_type()> GetTimeToNextAction) :
    GetTimeToNextAction_(GetTimeToNextAction), Interaction(Action, [this]() { return GetTimeToNextAction_() == 0; })
{
}

time_type PredictableInteraction::GetTimeToNextAction() const
{
    return GetTimeToNextAction_();
}