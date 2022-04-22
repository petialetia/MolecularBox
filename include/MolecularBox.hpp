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

const coordinates_on_screen ORIGIN_COORDINATES_BY_DEFAULT = coordinates_on_screen({0, 0});
const coordinates_on_screen SINGLE_SEGMENT_LENGTH_BY_DEFAULT = coordinates_on_screen({10, 10});

const std::string WINDOW_NAME = "MolecularBox";

const object_coordinates SHELL_COORDINATES = object_coordinates({0, 0});
const coordinate_type SHELL_RADIUS = 250;

const time_type TIME_STEP = 1;

enum simulation_status
{
    SIMULATION_CONTINUES,
    SIMULATION_ENDED
};

coordinates_on_screen GetScreenCoordinates(object_coordinates relative_coordinates);
CoordinateSystem<coordinate_on_screen_type, coordinate_type> GetCoordinateSystem();

subsription_storage GetSubscriptionsByDefault(const ObjectStorage& objects, IdStorage<Interaction>& interactions);
std::function<void(id_type)> GetAddDrawSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions);
std::function<void()> GetDrawAction(const ObjectStorage& objects, id_type id);
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
