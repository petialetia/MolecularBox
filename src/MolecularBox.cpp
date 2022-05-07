#include <MolecularBox.hpp>

int main()
{
    auto resolution = GetGraphic()->GetResolution(0);
    GetGraphic()->CreateWindow(WINDOW_NAME, window_coordinates({resolution[0]/4, resolution[1]/4}), {resolution[0]/2, resolution[1]/2});

    Simulation simulation = Simulation(GetCoordinateSystem());

    simulation.AddSubscriptionByDefault(GetAddDrawSubscription(simulation));
    simulation.AddSubscriptionByDefault(GetAddCollisionSubscription(simulation));

    SpawnDefaultObjects(simulation);

    RunStepByStepSimulation(simulation);

    return 0;
}

molecular_box_coordinate_system GetCoordinateSystem()
{
    auto window_size = GetGraphic()->GetWindowSize();

    return CoordinateSystem<coordinate_on_screen_type, coordinate_type>(Coordinates({static_cast<coordinate_on_screen_type>(window_size[0]) / 2, 
                                                                                     static_cast<coordinate_on_screen_type>(window_size[1]) / 2}), 
                                                                        SINGLE_SEGMENT_LENGTH_BY_DEFAULT);
}

std::function<void(id_type)> GetAddDrawSubscription(Simulation& simulation)
{
    return [&simulation](id_type id) {
        simulation.GetInteractions().AddObjectToDraw(id);
    };
}

std::function<void(id_type)> GetAddCollisionSubscription(Simulation& simulation)
{
    return [&simulation](id_type new_object_id) {
        std::for_each(simulation.GetObjects().objects_cbegin(), simulation.GetObjects().objects_cend(), [new_object_id, &simulation](const auto& pair){
            const auto& [id, object] = pair;

            if (id == new_object_id)
            {
                return;
            }

            simulation.GetInteractions().AddInteraction(Interaction(GetCollisionAction(new_object_id, id, simulation.GetObjects()), 
                                                                    GetCollisionCheck( new_object_id, id, simulation.GetObjects())));
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

void SpawnDefaultObjects(Simulation& simulation)
{
    SpawnShell(simulation);
    SpawnMolecules(simulation);
}

void SpawnShell(Simulation& simulation)
{
    simulation.AddObjectWithDefaultSubscriptions(Ring(SHELL_INNER_RADIUS, SHELL_WIDTH), SHELL_COORDINATES, SHELL_COLOR);
}

void SpawnMolecules(Simulation& simulation)
{
    srand(time(NULL));

    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({0,    0}),    color({255, 0,   255, 255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({-164, 0}),    color({0,   0,   255, 255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({-82,  -116}), color({255, 0,   0,   255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({82,   -116}), color({255, 255, 0,   255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({164,  0}),    color({255, 255, 255, 255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({82,   116}),  color({0,   255, 255, 255}), 
                                                 GetMoleculeSpeed());
    simulation.AddObjectWithDefaultSubscriptions(Circle(GetMoleculeRadius()), object_coordinates({-82,  116}),  color({0,   255, 0,   255}), 
                                                 GetMoleculeSpeed());
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

void RunStepByStepSimulation(Simulation& simulation)
{
    simulation.TryDraw();
    GetTimer()->Delay(DELAY);

    while (ProcessEvents() != SIMULATION_ENDED)
    {
        simulation.Step();
        GetTimer()->Delay(DELAY);
    }
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
