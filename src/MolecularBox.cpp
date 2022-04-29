#include <MolecularBox.hpp>

#include <iostream>

int main()
{
    auto resolution = GetGraphic()->GetResolution(0);
    GetGraphic()->CreateWindow(WINDOW_NAME, window_coordinates({resolution[0]/4, resolution[1]/4}), {resolution[0]/2, resolution[1]/2});

    time_type global_time = 0;

    ObjectStorage objects;

    auto coordinate_system = GetCoordinateSystem();

    DrawningInteraction drawning_interaction = DrawningInteraction(global_time, 0, DRAWNING_PERIOD_BY_DEFAULT, objects, coordinate_system, BACKGROUND_COLOR);
    IdStorage<Interaction> interactions;
    IdStorage<PredictableInteraction> predictable_interactions;

    auto subscriptions_by_default = GetSubscriptionsByDefault(objects, interactions, drawning_interaction);

    SpawnDefaultObjects(objects, subscriptions_by_default);

    StepByStepSimulation(drawning_interaction, interactions, objects, global_time);

    return 0;
}

molecular_box_coordinate_system GetCoordinateSystem()
{
    auto window_size = GetGraphic()->GetWindowSize();

    return CoordinateSystem<coordinate_on_screen_type, coordinate_type>(Coordinates({static_cast<coordinate_on_screen_type>(window_size[0]) / 2, 
                                                                                     static_cast<coordinate_on_screen_type>(window_size[1]) / 2}), 
                                                                        SINGLE_SEGMENT_LENGTH_BY_DEFAULT);
}

subsription_storage GetSubscriptionsByDefault(const ObjectStorage& objects, IdStorage<Interaction>& interactions, DrawningInteraction& drawning_interaction)
{
    subsription_storage subscriptions_by_default = {};

    subscriptions_by_default.push_back(GetAddDrawSubscription(drawning_interaction));
    subscriptions_by_default.push_back(GetAddCollisionSubscription(objects, interactions));

    return subscriptions_by_default;
}

std::function<void(id_type)> GetAddDrawSubscription(DrawningInteraction& drawning_interaction)
{
    return [&drawning_interaction](id_type id) {
        drawning_interaction.AddObjectToDraw(id);
    };
}

std::function<void(id_type)> GetAddCollisionSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions)
{
    return [&objects, &interactions](id_type new_object_id) {
        std::for_each(objects.objects_cbegin(), objects.objects_cend(), [new_object_id, &objects, &interactions](const auto& pair){
            const auto& [id, object] = pair;

            if (id == new_object_id)
            {
                return;
            }

            interactions.AddElement(Interaction(GetCollisionAction(), GetCollisionCheck(new_object_id, id, objects)));
        });
    };
}

std::function<void()> GetCollisionAction()
{
    return []() {
        std::cout << "Collision is happened!!!" << std::endl;
    };
}

std::function<bool()> GetCollisionCheck(const id_type first_id, const id_type second_id, const ObjectStorage& objects)
{
    return [first_id, second_id, &objects]() {
        auto first_object  = objects.GetObject(first_id);
        auto first_object_coordinates = objects.GetCoordinates(first_id);
        auto first_object_speed = objects.GetSpeed(first_id);

        auto second_object = objects.GetObject(second_id);
        auto second_object_coordinates = objects.GetCoordinates(second_id);
        auto second_object_speed = objects.GetSpeed(second_id);

        return std::visit([&first_object_coordinates, &first_object_speed, &second_object_coordinates, &second_object_speed]
                          (auto& first_object, auto& second_object) {
            return CheckCollision(first_object,  first_object_coordinates,  first_object_speed,
                                  second_object, second_object_coordinates, second_object_speed);
        }, first_object, second_object);
    };
}

void SpawnDefaultObjects(ObjectStorage& objects, subsription_storage& subscriptions_by_default)
{
    SpawnShell(objects, subscriptions_by_default);
    SpawnMolecules(objects, subscriptions_by_default);
}

void SpawnShell(ObjectStorage& objects, subsription_storage& subscriptions_by_default)
{
    auto new_object_id = objects.AddObject(Ring(SHELL_INNER_RADIUS, SHELL_WIDTH), SHELL_COORDINATES, SHELL_COLOR, {10, 10});
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
    auto new_molecule_id = objects.AddObject(Circle(100), object_coordinates({0, 0}), {255, 0, 255, 255}, {20, 20});
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(30), object_coordinates({100, 100}), {0, 0, 255, 255}, {-30, 20});
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);
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

void StepByStepSimulation(DrawningInteraction& drawning_interaction, IdStorage<Interaction>& interactions, ObjectStorage& objects, time_type& global_time)
{
    CheckInteractions(drawning_interaction, interactions);
    GetTimer()->Delay(DELAY);

    while (ProcessEvents() != SIMULATION_ENDED)
    {
        MoveObjects(objects);
        global_time += TIME_STEP;

        CheckInteractions(drawning_interaction, interactions);
        GetTimer()->Delay(DELAY);
    }
}

void CheckInteractions(DrawningInteraction& drawning_interaction, IdStorage<Interaction>& interactions)
{
    if (drawning_interaction.CheckConditionForAction() == true)
    {
        drawning_interaction.Action();
    }

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
