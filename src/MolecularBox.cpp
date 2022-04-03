#include <include/MolecularBox.hpp>

int main()
{
    time_type global_time = 0;

    IdStorage<Interaction> interactions;
    IdStorage<PredictableInteraction> predictable_interactions;

    IdStorage<object> objects;

    speed_storage object_speeds;

    auto subscriptions_by_default = GetSubscriptionsByDefault();

    SpawnDefaultObjects(objects, subscriptions_by_default, object_speeds);

    StepByStepSimulation(objects, interactions, object_speeds, global_time);

    return 0;
}

subsription_storage GetSubscriptionsByDefault()
{
    subsription_storage subscriptions_by_default = {};

    subscriptions_by_default.push_back(GetDrawSubscription());
    subscriptions_by_default.push_back(GetCollisionSubscription());

    return subscriptions_by_default;
}

std::function<void(id_type)> GetDrawSubscription()
{
    return [](id_type) { return; };
}

std::function<void(id_type)> GetCollisionSubscription()
{
    return [](id_type) { return; };
}

void SpawnDefaultObjects(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, speed_storage& object_speeds)
{
    SpawnShell(objects, subscriptions_by_default);
    SpawnMolecules(objects, subscriptions_by_default, object_speeds);
}

void SpawnShell(IdStorage<object>& objects, subsription_storage& subscriptions_by_default)
{
    auto new_object_id = objects.AddElement(Circle(SHELL_COORDINATES, SHELL_RADIUS));
    SubscribeToDefaultInteractons(new_object_id, subscriptions_by_default);
}

void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default)
{
    for (auto& AddSubscription : subscriptions_by_default)
    {
        AddSubscription(object_id);
    }
}

void SpawnMolecules(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, speed_storage& object_speeds)
{
    return;
}

void StepByStepSimulation(IdStorage<object>& objects, IdStorage<Interaction>& interactions, speed_storage& object_speeds, 
                          time_type& global_time)
{
    while (true)
    {
        CheckInteractions(interactions);
        MoveObjects(objects, object_speeds);
        global_time += TIME_STEP;
    }
}

void CheckInteractions(IdStorage<Interaction>& interactions)
{
    for (auto& pair: interactions)
    {
        if (pair.second.CheckConditionForAction() == true)
        {
            pair.second.Action();
        }
    }
}

void MoveObjects(IdStorage<object>& objects, speed_storage& object_speeds, time_type time)
{
    for (auto& pair: objects)
    {
        Move(pair, object_speeds, time);
    }
}

void Move(std::pair<id_type, object> pair, speed_storage& object_speeds, time_type time)
{
    if (object_speeds.find(pair.first) == object_speeds.end())
    {
        return;
    }

    Move(pair.second, TermByTermMultiplication(object_speeds[pair.first], time));
}

void Move(object& object, offset_type offset)
{
    std::visit([&offset](Circle& object) { 
        Move(object, offset); 
    }, object);
}
