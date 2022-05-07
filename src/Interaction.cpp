#include <Interaction.hpp>

Interaction::Interaction(std::function<void()> Action, std::function<bool()> CheckConditionForAction) : 
    Action_(Action), CheckConditionForAction_(CheckConditionForAction)
{
}

Interaction::Interaction(Interaction&& other) :
    Action_(other.Action_), CheckConditionForAction_(other.CheckConditionForAction_)
{
}

Interaction& Interaction::operator=(Interaction&& other)
{
    Action_ = other.Action_;
    CheckConditionForAction_ = other.CheckConditionForAction_;

    return *this;
}

void Interaction::Action() const
{
    Action_();
}

bool Interaction::CheckConditionForAction() const
{
    return CheckConditionForAction_();
}

void Interaction::TryAction() const
{
    if (CheckConditionForAction_() == true)
    {
        Action_();
    }
}

PredictableInteraction::PredictableInteraction(std::function<void()> Action, std::function<time_type()> GetTimeToNextAction) :
    Interaction(Action, [GetTimeToNextAction]() { return GetTimeToNextAction() == 0; }), GetTimeToNextAction_(GetTimeToNextAction)
{
}

PredictableInteraction::PredictableInteraction(PredictableInteraction&& other) :
    PredictableInteraction(other.Action_, other.GetTimeToNextAction_)
{
}

PredictableInteraction& PredictableInteraction::operator=(PredictableInteraction&& other)
{
    Action_ = other.Action_;
    CheckConditionForAction_ = other.CheckConditionForAction_;
    GetTimeToNextAction_ = other.GetTimeToNextAction_;

    return *this;
}

time_type PredictableInteraction::GetTimeToNextAction() const
{
    return GetTimeToNextAction_();
}