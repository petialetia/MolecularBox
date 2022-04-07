#include <include/MolecularBox.hpp>

int main()
{
    time_type global_time = 0;

    IdStorage<Interaction> interactions;
    IdStorage<PredictableInteraction> predictable_interactions;

    IdStorage<object> objects;

    coordinate_storage object_coordinates;
    speed_storage object_speeds;

    auto subscriptions_by_default = GetSubscriptionsByDefault();

    SpawnDefaultObjects(objects, subscriptions_by_default, object_coordinates, object_speeds);

    StepByStepSimulation(interactions, object_coordinates, object_speeds, global_time);

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

void SpawnDefaultObjects(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, 
                         coordinate_storage& object_coordinates, speed_storage& object_speeds)
{
    SpawnShell(objects, subscriptions_by_default, object_coordinates);
    SpawnMolecules(objects, subscriptions_by_default, object_coordinates, object_speeds);
}

void SpawnShell(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, coordinate_storage& object_coordinates)
{
    auto new_object_id = objects.AddElement(Circle(SHELL_RADIUS));
    object_coordinates[new_object_id] = SHELL_COORDINATES;
    SubscribeToDefaultInteractons(new_object_id, subscriptions_by_default);
}

void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default)
{
    for (auto& AddSubscription : subscriptions_by_default)
    {
        AddSubscription(object_id);
    }
}

void SpawnMolecules(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, 
                    coordinate_storage& object_coordinates, speed_storage& object_speeds)
{
    return;
}

void StepByStepSimulation(IdStorage<Interaction>& interactions, 
                          coordinate_storage& object_coordinates, speed_storage& object_speeds, 
                          time_type& global_time)
{
    while (true)
    {
        CheckInteractions(interactions);
        MoveObjects(object_coordinates, object_speeds);
        global_time += TIME_STEP;
    }
}

void CheckInteractions(IdStorage<Interaction>& interactions)
{
    for (auto& [id, object]: interactions)
    {
        if (object.CheckConditionForAction() == true)
        {
            object.Action();
        }
    }
}

void MoveObjects(coordinate_storage& object_coordinates, speed_storage& object_speeds, time_type time)
{
    std::for_each(object_speeds.cbegin(), object_speeds.cend(), [&object_coordinates, time](const auto& pair){
        const auto& [id, speed] = pair;
        MoveOnOffset(object_coordinates[id], CalculateOffset(speed, time));    
    });
}

offset_type CalculateOffset(speed_type speed, time_type time)
{
    return TermByTermMultiplication(speed, time);
}

void MoveOnOffset(coordinates& object_coordinates, offset_type offset)
{
    TermByTermCompoundAddition(object_coordinates, offset);
}
