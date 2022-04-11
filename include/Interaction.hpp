#ifndef INTERACTION_HPP
#define INTERACTION_HPP

#include "UsingAliasMolecularBox.hpp"

#include <functional>

class Interaction
{
  private:

    std::function<void()> Action_ = []() { return; };
    std::function<bool()> CheckConditionForAction_ = []() { return true; };

  public:

    explicit Interaction(std::function<void()> Action, std::function<bool()> CheckConditionForAction); 

    Interaction(const Interaction&) = delete;
    Interaction(Interaction&) = delete;

    Interaction& operator=(const Interaction&) = delete;
    Interaction& operator=(Interaction&) = delete;

    void Action() const;

    bool CheckConditionForAction() const;
};

class PredictableInteraction : public Interaction
{
  private:

    std::function<time_type()> GetTimeToNextAction_ = []() { return 0; };

  public:

    explicit PredictableInteraction(std::function<void()> Action, std::function<time_type()> GetTimeToNextAction);

    PredictableInteraction(const Interaction&) = delete;
    PredictableInteraction(Interaction&) = delete;

    PredictableInteraction& operator=(const Interaction&) = delete;
    PredictableInteraction& operator=(Interaction&) = delete;

    time_type GetTimeToNextAction() const;
};

#endif /* INTERACTION_HPP */