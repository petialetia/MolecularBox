#include <include/UsingAlias.hpp>
#include <include/Shape.hpp>
#include <include/Interaction.hpp>

#include <include/IdStorage.hpp>

#include <vector>
#include <variant>
#include <unordered_map>
#include <cstdio>

using object = std::variant<Circle>;

using speed_type = std::vector<coordinate_type>;
using subsription_storage = std::vector<std::function<void(id_type)>>;
using coordinate_storage = std::unordered_map<id_type, coordinates>;
using speed_storage = std::unordered_map<id_type, speed_type>;

std::vector<coordinate_type> SHELL_COORDINATES = {0, 0};
coordinate_type SHELL_RADIUS = 0;

time_type TIME_STEP = 1;

subsription_storage GetSubscriptionsByDefault();
std::function<void(id_type)> GetDrawSubscription();
std::function<void(id_type)> GetCollisionSubscription();

void SpawnDefaultObjects(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, 
                         coordinate_storage& object_coordinates, speed_storage& object_speeds);
void SpawnShell(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, coordinate_storage& object_coordinates);
void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default);
void SpawnMolecules(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, 
                    coordinate_storage& object_coordinates, speed_storage& object_speeds);

void StepByStepSimulation(IdStorage<Interaction>& interactions, 
                          coordinate_storage& object_coordinates, speed_storage& object_speeds, 
                          time_type& global_time);
void CheckInteractions(IdStorage<Interaction>& interactions);
void MoveObjects(coordinate_storage& object_coordinates, speed_storage& object_speeds, time_type time = TIME_STEP);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(coordinates& object_coordinates, offset_type offset);                       
