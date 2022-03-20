#include "../include/MolecularBox.hpp"

int main()
{
    time_type global_time = 0;

    std::vector<Interaction<Predictable>> predictable_interactions;
    std::vector<Interaction<Continuus>> continuus_interactions;

    auto subscriptions_by_default = GetSubscriptionsByDefault();

    auto objects = SpawnDefaultObjects(subscriptions_by_default);

    StepByStepSimulation(objects, predictable_interactions, continuus_interactions, global_time);

    return 0;
}

std::vector<std::function<void(Object*)>> GetSubscriptionsByDefault()
{
    std::vector<std::function<void(Object*)>> subscriptions_by_default = {};

    subscriptions_by_default.push_back(GetDrawSubscription());
    subscriptions_by_default.push_back(GetCollisionSubscription());

    return subscriptions_by_default;
}

std::function<void(Object*)> GetDrawSubscription()
{
    return [](Object*) { return; };
}

std::function<void(Object*)> GetCollisionSubscription()
{
    return [](Object*) { return; };
}

std::vector<Object*> SpawnDefaultObjects(std::vector<std::function<void(Object*)>>& subscriptions_by_default)
{
    std::vector<Object*> objects = {};
    SpawnShell(objects, subscriptions_by_default);
    SpawnMolecules(objects, subscriptions_by_default);

    return objects;
}

void SpawnShell(std::vector<Object*>& objects, std::vector<std::function<void(Object*)>>& subscriptions_by_default)
{
    Object* new_object_ptr = new Circle(SHELL_COORDINATES, SHELL_RADIUS);
    objects.push_back(new_object_ptr);
    SubscribeToDefaultInteractons(new_object_ptr, subscriptions_by_default);
}

void SubscribeToDefaultInteractons(Object* object_ptr, std::vector<std::function<void(Object*)>>& subscriptions_by_default)
{
    for (std::function<void(Object*)> AddSubscription : subscriptions_by_default)
    {
        AddSubscription(object_ptr);
    }
}

void SpawnMolecules(std::vector<Object*>& objects, std::vector<std::function<void(Object*)>>& subscriptions_by_default)
{
    return;
}

void StepByStepSimulation(std::vector<Object*>& objects, std::vector<Interaction<Predictable>>& predictable_interactions, 
                          std::vector<Interaction<Continuus>>& continuus_interactions, time_type& global_time)
{
    while (true)
    {
        CheckInteractions(predictable_interactions, continuus_interactions);
        MoveObjects(objects);
        global_time += TIME_STEP;
    }
}

void CheckInteractions(std::vector<Interaction<Predictable>>& predictable_interactions, std::vector<Interaction<Continuus>>& continuus_interactions)
{
    for (auto interaction : continuus_interactions)
    {
        if (interaction.GetTimeToNextAction() == 0)
        {
            interaction.Action();
        }
    }
}

void MoveObjects(std::vector<Object*>& objects)
{
    return;
}
