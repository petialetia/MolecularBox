#include <StepByStepSimulation.hpp>

void MoveObjects(ObjectStorage& objects, time_type time)
{
    std::for_each(objects.speeds_cbegin(), objects.speeds_cend(), [&objects, time](const auto& pair){
        const auto& [id, speed] = pair;
        MoveOnOffset(objects.GetCoordinates(id), CalculateOffset(speed, time));    
    });
}

offset_type CalculateOffset(speed_type speed, time_type time)
{
    return speed * time;
}

void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset)
{
    object_coordinates += offset;
}

const time_type& StepByStepSimulation::GetGlobalTime()
{
    return global_time_;
}

ObjectStorage& StepByStepSimulation::GetObjects()
{
    return object_storage_;
}

InteractionStorage& StepByStepSimulation::GetInteractions()
{
    return interaction_storage_;
}


void StepByStepSimulation::AddSubscriptionByDefault(std::function<void(id_type)> subscription)
{
    subscriptions_by_default_.push_back(subscription);
}

void StepByStepSimulation::SubscribeToDefaultInteraction(id_type id)
{
    for (auto& AddSubscription : subscriptions_by_default_)
    {
        AddSubscription(id);
    }
}

void StepByStepSimulation::CheckInteractions()
{
    interaction_storage_.CheckInteractions();
}

void StepByStepSimulation::Step()
{
    MoveObjects(object_storage_, time_step_);
    global_time_+= time_step_;

    CheckInteractions();
}