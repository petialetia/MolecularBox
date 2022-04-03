#include <include/UsingAlias.hpp>
#include <include/Object.hpp>
#include <include/Interaction.hpp>

#include <include/IdStorage.hpp>

#include <vector>
#include <variant>
#include <unordered_map>
#include <cstdio>

using speed_type = std::vector<coordinate_type>;
using subsription_storage = std::vector<std::function<void(id_type)>>;
using speed_storage = std::unordered_map<id_type, speed_type>;

std::vector<coordinate_type> SHELL_COORDINATES = {0, 0};
coordinate_type SHELL_RADIUS = 0;

time_type TIME_STEP = 1;

subsription_storage GetSubscriptionsByDefault();
std::function<void(id_type)> GetDrawSubscription();
std::function<void(id_type)> GetCollisionSubscription();

void SpawnDefaultObjects(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, speed_storage& object_speeds);
void SpawnShell(IdStorage<object>& objects, subsription_storage& subscriptions_by_default);
void SubscribeToDefaultInteractons(id_type object_id, subsription_storage& subscriptions_by_default);
void SpawnMolecules(IdStorage<object>& objects, subsription_storage& subscriptions_by_default, speed_storage& object_speeds);

void StepByStepSimulation(IdStorage<object>& objects, IdStorage<Interaction>& interactions, speed_storage& object_speeds, 
                          time_type& global_time);
void CheckInteractions(IdStorage<Interaction>& interactions);
void MoveObjects(IdStorage<object>& objects, speed_storage& object_speeds, time_type time = TIME_STEP);    
void Move(std::pair<id_type, object> pair, speed_storage& object_speeds, time_type time);
void Move(object& object, offset_type offset);                            
