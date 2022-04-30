#ifndef MOLECULAR_BOX_HPP
#define MOLECULAR_BOX_HPP

#include "UsingAliasMolecularBox.hpp"

#include "TimerAdapter/SDL2TimerFunctions.hpp"
#include "TimerAdapter/SDL2TimerImplementation.hpp"

#include "Shape.hpp"
#include "Interaction.hpp"
#include "ObjectStorage.hpp"
#include "Coordinates.hpp"
#include "CoordinateSystem.hpp"

#include "GetGraphic.hpp"
#include "DrawningInteraction.hpp"

#include "CheckCollision.hpp"
#include "ProcessCollision.hpp"

#include <vector>
#include <variant>
#include <cstdio>
#include <optional>

using subsription_storage = std::vector<std::function<void(id_type)>>;

const milliseconds DELAY = 500;

const std::string WINDOW_NAME = "MolecularBox";

const color BACKGROUND_COLOR = {.red = 0,
                                .green = 0,
                                .blue = 0,
                                .alpha = 0};

const coordinate_on_screen_type SINGLE_SEGMENT_LENGTH_BY_DEFAULT = 1;

const object_coordinates SHELL_COORDINATES = object_coordinates({0, 0});
const coordinate_type SHELL_INNER_RADIUS = 250;
const coordinate_type SHELL_WIDTH = 5;
const color SHELL_COLOR = {.red = 0,
                           .green = 255,
                           .blue = 0,
                           .alpha = 255};

const time_type TIME_STEP = 1;
const time_type DRAWNING_PERIOD_BY_DEFAULT = 1;

enum simulation_status
{
    SIMULATION_CONTINUES,
    SIMULATION_ENDED
};

auto GetTimer()
{
    return GetSDL2TimerImplementation();
}

CoordinateSystem<coordinate_on_screen_type, coordinate_type> GetCoordinateSystem();

subsription_storage GetSubscriptionsByDefault(ObjectStorage& objects, IdStorage<Interaction>& interactions, DrawningInteraction& drawning_interaction);

std::function<void(id_type)> GetAddDrawSubscription(DrawningInteraction& drawning_interaction);

std::function<void(id_type)> GetAddCollisionSubscription(ObjectStorage& objects, IdStorage<Interaction>& interactions);
std::function<void()> GetCollisionAction(const id_type first_id, const id_type second_id, ObjectStorage& objects);
std::function<bool()> GetCollisionCheck(const id_type first_id, const id_type second_id, const ObjectStorage& objects);

void SpawnDefaultObjects(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SpawnShell(ObjectStorage& objects, subsription_storage& subscriptions_by_default);
void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default);
void SpawnMolecules(ObjectStorage& objects, subsription_storage& subscriptions_by_default);

simulation_status ProcessEvents();

void StepByStepSimulation(DrawningInteraction& drawning_interaction, IdStorage<Interaction>& interactions, ObjectStorage& objects, time_type& global_time);
void CheckInteractions(DrawningInteraction& drawning_interaction, IdStorage<Interaction>& interactions);
void MoveObjects(ObjectStorage& objects, time_type time = TIME_STEP);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset);      

#endif /* MOLECULAR_BOX_HPP */
