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

#include <vector>
#include <variant>
#include <unordered_map>
#include <cstdio>

using Graphic = SDL2GraphicImplementation;
using Timer = SDL2TimerImplementation;

using subsription_storage = std::vector<std::function<void(id_type)>>;

std::string WINDOW_NAME = "MolecularBox";

ObjectCoordinates SHELL_COORDINATES = ObjectCoordinates({0, 0});
coordinate_type SHELL_RADIUS = 0;

time_type TIME_STEP = 1;

subsription_storage GetSubscriptionsByDefault();
std::function<void(id_type)> GetDrawSubscription();
std::function<void(id_type)> GetCollisionSubscription();

void SpawnDefaultObjects(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SpawnShell(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default);
void SpawnMolecules(ObjectStorage& objects, subsription_storage& subscriptions_by_default);

void StepByStepSimulation(IdStorage<Interaction>& interactions, ObjectStorage& objects, time_type& global_time);
void CheckInteractions(IdStorage<Interaction>& interactions);
void MoveObjects(ObjectStorage& objects, time_type time = TIME_STEP);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(coordinates& object_coordinates, offset_type offset);                       
