#ifndef MOLECULAR_BOX_HPP
#define MOLECULAR_BOX_HPP

#include "UsingAliasMolecularBox.hpp"

#include "Shape.hpp"
#include "Interaction.hpp"
#include "ObjectStorage.hpp"
#include "InteractionStorage.hpp"
#include "Coordinates.hpp"
#include "CoordinateSystem.hpp"

#include "GraphicAdapter/SDL2GraphicImplementation.hpp"

#include "DrawningInteraction.hpp"

#include "CheckCollision.hpp"
#include "ProcessCollision.hpp"

#include "StepByStepSimulation.hpp"

#include <vector>
#include <variant>
#include <cstdio>

const uint FPS_BY_DEFAULT = 60;
const milliseconds FRAME_TIME = 1000 / FPS_BY_DEFAULT;

const std::string WINDOW_NAME = "MolecularBox";

const coordinate_on_screen_type SINGLE_SEGMENT_LENGTH_BY_DEFAULT = 1;

const time_type TIME_STEP = 1.0/4096;

const time_type DRAWNING_PERIOD_BY_DEFAULT = 1.0/8;

const color BACKGROUND_COLOR = {.red = 0,
                                .green = 0,
                                .blue = 0,
                                .alpha = 0};

const object_coordinates SHELL_COORDINATES = object_coordinates({0, 0});
const coordinate_type SHELL_INNER_RADIUS = 250;
const coordinate_type SHELL_WIDTH = 10;
const color SHELL_COLOR = {.red   = 127,
                           .green = 127,
                           .blue  = 127,
                           .alpha = 255};

const uint MOLECULES_MAX_RADIUS = 70;
const uint MOLECULES_MIN_RADIUS = 30;

const coordinate_type AREA_TO_MASS_KOEF = 1;

const uint MOLECULES_START_SPEED = 30;

using Simulation = StepByStepSimulation;

auto GetTimer()
{
    static auto timer_implementation = GetSDL2TimerImplementation();
    return &timer_implementation;
}

auto GetGraphic()
{
    static auto graphic_implementation = GetSDL2GraphicImplementation();
    return &graphic_implementation;
}

molecular_box_coordinate_system GetCoordinateSystem();

subsription_storage GetSubscriptionsByDefault(ObjectStorage& objects, InteractionStorage& interaction_storage);

std::function<void(id_type)> GetAddDrawSubscription(Simulation& simulation);

std::function<void(id_type)> GetAddCollisionSubscription(Simulation& simulation);
std::function<void()> GetCollisionAction(const id_type first_id, const id_type second_id, ObjectStorage& objects);
std::function<bool()> GetCollisionCheck(const id_type first_id, const id_type second_id, const ObjectStorage& objects);

void SpawnDefaultObjects(Simulation& simulation);
void SpawnShell(Simulation& simulation);
void SpawnMolecules(Simulation& simulation);

void SpawnMolecule(Simulation& simulation, object_coordinates coordinates, color color);
coordinate_type GetMoleculeRadius();
mass_type GetMoleculeMass(coordinate_type radius);
speed_type GetMoleculeSpeed();

simulation_status ProcessEvents();

#endif /* MOLECULAR_BOX_HPP */
