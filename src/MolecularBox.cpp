#include <MolecularBox.hpp>

int main()
{
    auto resolution = GetGraphic()->GetResolution(0);
    GetGraphic()->CreateWindow(WINDOW_NAME, window_coordinates({resolution[0]/4, resolution[1]/4}), {resolution[0]/2, resolution[1]/2});

    time_type global_time = 0;

    IdStorage<Interaction> interactions;
    IdStorage<PredictableInteraction> predictable_interactions;

    ObjectStorage objects;

    auto coordinate_system = GetCoordinateSystem();

    auto subscriptions_by_default = GetSubscriptionsByDefault(objects, interactions, coordinate_system);

    SpawnDefaultObjects(objects, subscriptions_by_default);

    StepByStepSimulation(interactions, objects, global_time);

    return 0;
}

molecular_box_coordinate_system GetCoordinateSystem()
{
    return CoordinateSystem<coordinate_on_screen_type, coordinate_type>(ORIGIN_COORDINATES_BY_DEFAULT, SINGLE_SEGMENT_LENGTH_BY_DEFAULT);
}

subsription_storage GetSubscriptionsByDefault(const ObjectStorage& objects, IdStorage<Interaction>& interactions, 
                                              const molecular_box_coordinate_system& coordinate_system)
{
    subsription_storage subscriptions_by_default = {};

    subscriptions_by_default.push_back(GetAddDrawSubscription(objects, interactions, coordinate_system));
    subscriptions_by_default.push_back(GetAddCollisionSubscription());

    return subscriptions_by_default;
}

std::function<void(id_type)> GetAddDrawSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions, 
                                                    const molecular_box_coordinate_system& coordinate_system)
{
    return [&objects, &coordinate_system, &interactions](id_type id) {
        interactions.AddElement(Interaction(GetDrawAction(objects, coordinate_system, id), GetDrawCheck()));
    };
}

std::function<void()> GetDrawAction(const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, id_type id)
{
    return [&objects, &coordinate_system, id]() { 
        auto object = objects.GetObject(id);
        auto relative_object_coordinates = objects.GetCoordinates(id);
        color object_color = objects.GetColor(id);

        DrawObject(GetGraphic(), coordinate_system, object, relative_object_coordinates, object_color);
    };
}

std::function<bool()> GetDrawCheck()
{
    return []() {
        return true;
    };
}

std::function<void(id_type)> GetAddCollisionSubscription()
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
    auto new_object_id = objects.AddObject(Circle(SHELL_RADIUS), SHELL_COORDINATES, SHELL_COLOR);
    SubscribeToDefaultInteractons(new_object_id, subscriptions_by_default);

    new_object_id = objects.AddObject(Circle(5), SHELL_COORDINATES, {255, 0, 255, 255}, {20, 20});
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
    CheckInteractions(interactions);

    GetGraphic()->Refresh();
    GetTimer()->Delay(DELAY);

    while (ProcessEvents() != SIMULATION_ENDED)
    {
        GetGraphic()->ClearWindow(BACKGROUND_COLOR);

        MoveObjects(objects);
        global_time += TIME_STEP;

        CheckInteractions(interactions);

        GetGraphic()->Refresh();
        GetTimer()->Delay(DELAY);
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
    return object_coordinates(speed) * time;
}

void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset)
{
    object_coordinates += offset;
}
