#include <MolecularBox.hpp>

int main()
{
    auto resolution = GetGraphic()->GetResolution(0);
    GetGraphic()->CreateWindow(WINDOW_NAME, window_coordinates({resolution[0]/4, resolution[1]/4}), {resolution[0]/2, resolution[1]/2});

    time_type global_time = 0;

    ObjectStorage objects;

    auto coordinate_system = GetCoordinateSystem();

    InteractionStorage interaction_storage(global_time, 0, DRAWNING_PERIOD_BY_DEFAULT, objects, coordinate_system, BACKGROUND_COLOR);

    auto subscriptions_by_default = GetSubscriptionsByDefault(objects, interaction_storage);

    SpawnDefaultObjects(objects, subscriptions_by_default);

    StepByStepSimulation(interaction_storage, objects, global_time);

    return 0;
}

molecular_box_coordinate_system GetCoordinateSystem()
{
    auto window_size = GetGraphic()->GetWindowSize();

    return CoordinateSystem<coordinate_on_screen_type, coordinate_type>(Coordinates({static_cast<coordinate_on_screen_type>(window_size[0]) / 2, 
                                                                                     static_cast<coordinate_on_screen_type>(window_size[1]) / 2}), 
                                                                        SINGLE_SEGMENT_LENGTH_BY_DEFAULT);
}

subsription_storage GetSubscriptionsByDefault(ObjectStorage& objects, InteractionStorage& interaction_storage)
{
    subsription_storage subscriptions_by_default = {};

    subscriptions_by_default.push_back(GetAddDrawSubscription(interaction_storage));
    subscriptions_by_default.push_back(GetAddCollisionSubscription(objects, interaction_storage));

    return subscriptions_by_default;
}

std::function<void(id_type)> GetAddDrawSubscription(InteractionStorage& interaction_storage)
{
    return [&interaction_storage](id_type id) {
        interaction_storage.AddObjectToDraw(id);
    };
}

std::function<void(id_type)> GetAddCollisionSubscription(ObjectStorage& objects, InteractionStorage& interaction_storage)
{
    return [&objects, &interaction_storage](id_type new_object_id) {
        std::for_each(objects.objects_cbegin(), objects.objects_cend(), [new_object_id, &objects, &interaction_storage](const auto& pair){
            const auto& [id, object] = pair;

            if (id == new_object_id)
            {
                return;
            }

            interaction_storage.AddInteraction(Interaction(GetCollisionAction(new_object_id, id, objects), GetCollisionCheck(new_object_id, id, objects)));
        });
    };
}

std::function<void()> GetCollisionAction(const id_type first_id, const id_type second_id, ObjectStorage& objects)
{
    return [first_id, second_id, &objects]() {
        auto first_object  = objects.GetObject(first_id);
        auto second_object = objects.GetObject(second_id);

        std::visit([first_id, second_id, &objects](auto& first_object, auto& second_object) {
            ProcessCollision(first_id, first_object, second_id, second_object, objects);
        }, first_object, second_object);
    };
}

std::function<bool()> GetCollisionCheck(const id_type first_id, const id_type second_id, const ObjectStorage& objects)
{
    return [first_id, second_id, &objects]() {
        auto first_object  = objects.GetObject(first_id);
        auto second_object = objects.GetObject(second_id);

        return std::visit([first_id, second_id, &objects](auto& first_object, auto& second_object) {
            return CheckCollision(first_id, first_object, second_id, second_object, objects);
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
    auto new_object_id = objects.AddObject(Ring(SHELL_INNER_RADIUS, SHELL_WIDTH), SHELL_COORDINATES, SHELL_COLOR);
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
    srand(time(NULL));

    auto new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({0, 0}), {255, 0, 255, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({-164, 0}), {0, 0, 255, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({-82, -116}), {255, 0, 0, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({82, -116}), {255, 255, 0, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({164, 0}), {255, 255, 255, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({82, 116}), {0, 255, 255, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);

    new_molecule_id = objects.AddObject(Circle(GetMoleculeRadius()), object_coordinates({-82, 116}), {0, 255, 0, 255}, GetMoleculeSpeed());
    SubscribeToDefaultInteractons(new_molecule_id, subscriptions_by_default);
}

coordinate_type GetMoleculeRadius()
{
    return static_cast<coordinate_type>(rand() % (MOLECULES_MAX_RADIUS - MOLECULES_MIN_RADIUS + 1) + MOLECULES_MIN_RADIUS);
}

speed_type GetMoleculeSpeed()
{
    auto x_signum = (rand() % 2) * 2 - 1;
    auto y_signum = (rand() % 2) * 2 - 1;

    auto x_speed = rand() % MOLECULES_START_SPEED;
    auto y_speed = sqrt(MOLECULES_START_SPEED * MOLECULES_START_SPEED - x_speed * x_speed);

    return speed_type({x_signum * static_cast<coordinate_type>(x_speed), y_signum * y_speed});
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

void StepByStepSimulation(InteractionStorage& interaction_storage, ObjectStorage& objects, time_type& global_time)
{
    interaction_storage.CheckInteractions();
    GetTimer()->Delay(DELAY);

    while (ProcessEvents() != SIMULATION_ENDED)
    {
        MoveObjects(objects, TIME_STEP);
        global_time += TIME_STEP;

        interaction_storage.CheckInteractions();
        GetTimer()->Delay(DELAY);
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
    return speed * time;
}

void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset)
{
    object_coordinates += offset;
}
