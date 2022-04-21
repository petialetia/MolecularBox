#include <MolecularBox.hpp>

int main()
{
    auto resolution = GetSDL2GraphicImplementation()->GetResolution(0);
    GetSDL2GraphicImplementation()->CreateWindow(WINDOW_NAME, {resolution[0]/4, resolution[1]/4}, {resolution[0]/2, resolution[1]/2});
    /*GetSDL2GraphicImplementation()->DrawCircle({100, 100}, 100, {255, 0, 0, 255});
    GetSDL2GraphicImplementation()->DrawCircleRegion({resolution[0]/2 - 200, resolution[1]/2 - 200}, 200, {0, 255, 255, 255});
    GetSDL2GraphicImplementation()->Refresh();

    GetSDL2TimerImplementation()->Delay(3000);*/

    time_type global_time = 0;

    IdStorage<Interaction> interactions;
    IdStorage<PredictableInteraction> predictable_interactions;

    ObjectStorage objects;

    auto subscriptions_by_default = GetSubscriptionsByDefault();

    SpawnDefaultObjects(objects, subscriptions_by_default);

    StepByStepSimulation(interactions, objects, global_time);

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

void SpawnDefaultObjects(ObjectStorage& objects, subsription_storage& subscriptions_by_default)
{
    SpawnShell(objects, subscriptions_by_default);
    SpawnMolecules(objects, subscriptions_by_default);
}

void SpawnShell(ObjectStorage& objects, subsription_storage& subscriptions_by_default)
{
    auto new_object_id = objects.AddObject(Circle(SHELL_RADIUS), SHELL_COORDINATES);
    SubscribeToDefaultInteractons(new_object_id, subscriptions_by_default);
}

void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default)
{
    for (auto& AddSubscription : subscriptions_by_default)
    {
        AddSubscription(object_id);
    }
}

void SpawnMolecules(ObjectStorage& objects, subsription_storage& subscriptions_by_default)
{
    return;
}

simulation_status ProcessEvents()
{
    //TODO: Rewrite on event adapter

    static SDL_Event event;


    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            return SIMULATION_ENDED;
        }


        if  (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            {
                return SIMULATION_ENDED;
            }
        }
    }

    return SIMULATION_CONTINUES;
}

void StepByStepSimulation(IdStorage<Interaction>& interactions, ObjectStorage& objects, time_type& global_time)
{
    while (ProcessEvents() != SIMULATION_ENDED)
    {
        CheckInteractions(interactions);
        MoveObjects(objects);
        global_time += TIME_STEP;
    }
}

void CheckInteractions(IdStorage<Interaction>& interactions)
{
    for (auto& [id, interaction]: interactions)
    {
        if (interaction.CheckConditionForAction() == true)
        {
            interaction.Action();
        }
    }
}

void MoveObjects(ObjectStorage& objects, time_type time)
{
    std::for_each(objects.speeds_cbegin(), objects.speeds_cend(), [&objects, time](const auto& pair){
        const auto& [id, speed] = pair;
        MoveOnOffset(objects.GetCoordinates(id), CalculateOffset(speed, time));    
    });
}

offset_type CalculateOffset(speed_type speed, time_type time)
{
    return ObjectCoordinates(speed) * time;
}

void MoveOnOffset(coordinates& object_coordinates, offset_type offset)
{
    object_coordinates += offset;
}
