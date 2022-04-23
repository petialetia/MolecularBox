#include "UsingAliasMolecularBox.hpp"

#include "GraphicAdapter/SDL2GraphicFunctions.hpp"
#include "GraphicAdapter/SDL2GraphicImplementation.hpp"

#include "TimerAdapter/SDL2TimerFunctions.hpp"
#include "TimerAdapter/SDL2TimerImplementation.hpp"

#include "Shape.hpp"
#include "Interaction.hpp"
#include "ObjectStorage.hpp"
#include "Coordinates.hpp"
#include "CoordinateSystem.hpp"

#include "DrawObject.hpp"

#include <vector>
#include <variant>
#include <unordered_map>
#include <cstdio>

using subsription_storage = std::vector<std::function<void(id_type)>>;

const coordinates_on_screen ORIGIN_COORDINATES_BY_DEFAULT = coordinates_on_screen({100, 100});
const coordinate_on_screen_type SINGLE_SEGMENT_LENGTH_BY_DEFAULT = 1;

const milliseconds DELAY = 500;

const std::string WINDOW_NAME = "MolecularBox";

const object_coordinates SHELL_COORDINATES = object_coordinates({0, 0});
const coordinate_type SHELL_RADIUS = 20;

const time_type TIME_STEP = 1;

const color BACKGROUND_COLOR = {.red = 0,
                                .green = 0,
                                .blue = 0,
                                .alpha = 0};

enum simulation_status
{
    SIMULATION_CONTINUES,
    SIMULATION_ENDED
};

auto GetGraphic()
{
    return GetSDL2GraphicImplementation();
}

auto GetTimer()
{
    return GetSDL2TimerImplementation();
}

CoordinateSystem<coordinate_on_screen_type, coordinate_type> GetCoordinateSystem();

subsription_storage GetSubscriptionsByDefault(const ObjectStorage& objects, IdStorage<Interaction>& interactions, 
                                              const molecular_box_coordinate_system& coordinate_system);
std::function<void(id_type)> GetAddDrawSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions, 
                                                    const molecular_box_coordinate_system& coordinate_system);
std::function<void()> GetDrawAction(const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, id_type id);
std::function<bool()> GetDrawCheck();
std::function<void(id_type)> GetAddCollisionSubscription();

void SpawnDefaultObjects(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SpawnShell(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default);
void SpawnMolecules(ObjectStorage& objects, subsription_storage& subscriptions_by_default);

simulation_status ProcessEvents();

void StepByStepSimulation(IdStorage<Interaction>& interactions, ObjectStorage& objects, time_type& global_time);
void CheckInteractions(IdStorage<Interaction>& interactions);
void MoveObjects(ObjectStorage& objects, time_type time = TIME_STEP);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset);                       
