#ifndef MOLECULAR_BOX_HPP
#define MOLECULAR_BOX_HPP

#include "UsingAliasMolecularBox.hpp"

#include "Shape.hpp"
#include "Interaction.hpp"
#include "ObjectStorage.hpp"
#include "InteractionStorage.hpp"
#include "Coordinates.hpp"
#include "CoordinateSystem.hpp"

#include "GetGraphic.hpp"
#include "DrawningInteraction.hpp"

#include "CheckCollision.hpp"
#include "ProcessCollision.hpp"

#include "StepByStepSimulation.hpp"

#include <vector>
#include <variant>
#include <cstdio>

const std::string WINDOW_NAME = "MolecularBox";

const coordinate_on_screen_type SINGLE_SEGMENT_LENGTH_BY_DEFAULT = 1;

const object_coordinates SHELL_COORDINATES = object_coordinates({0, 0});
const coordinate_type SHELL_INNER_RADIUS = 250;
const coordinate_type SHELL_WIDTH = 10;
const color SHELL_COLOR = {.red = 0,
                           .green = 255,
                           .blue = 0,
                           .alpha = 255};

const uint MOLECULES_MAX_RADIUS = 70;
const uint MOLECULES_MIN_RADIUS = 30;

const uint MOLECULES_START_SPEED = 30;

using Simulation = StepByStepSimulation<SDL2TimerImplementation>;

auto GetTimer()
{
    return GetSDL2TimerImplementation();
}

molecular_box_coordinate_system GetCoordinateSystem();

subsription_storage GetSubscriptionsByDefault(ObjectStorage& objects, InteractionStorage& interaction_storage);

std::function<void(id_type)> GetAddDrawSubscription(InteractionStorage& interaction_storage);

std::function<void(id_type)> GetAddCollisionSubscription(ObjectStorage& objects, InteractionStorage& interaction_storage);
std::function<void()> GetCollisionAction(const id_type first_id, const id_type second_id, ObjectStorage& objects);
std::function<bool()> GetCollisionCheck(const id_type first_id, const id_type second_id, const ObjectStorage& objects);

void SpawnDefaultObjects(Simulation& simulation);
void SpawnShell(Simulation& simulation);
void SpawnMolecules(Simulation& simulation);

coordinate_type GetMoleculeRadius();
speed_type GetMoleculeSpeed();

//void StepByStepSimulation(InteractionStorage& interaction_storage, ObjectStorage& objects, time_type& global_time);
     

#endif /* MOLECULAR_BOX_HPP */
