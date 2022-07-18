#ifndef INTERACTION_INTERFACE_HPP
#define INTERACTION_INTERFACE_HPP

template<typename Implementation>
class InteractionInterface
{
  public:
    void Action()
    {
        this->GetImplementation()->Action();
    }

    bool CheckConditionForAction()
    {
        return this->GetImplementation()->CheckConditionForAction();
    }

  private:
    Implementation* GetImplementation()
    {
        return static_cast<Implementation*>(this);
    }
};

template<typename InteractionImplementation>
void TryAction(InteractionImplementation& interaction)
{
    if (interaction.CheckConditionForAction())
    {
        interaction.Action();
    }
}

#endif /* INTERACTION_INTERFACE_HPP */
