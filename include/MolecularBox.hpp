#include <vector>

#include "UsingAlias.hpp"
#include "Object.hpp"
#include "Interaction.hpp"

std::vector<coordinate_type> SHELL_COORDINATES = {0, 0};
coordinate_type SHELL_RADIUS = 0;

time_type TIME_STEP = 1;
size_t NUM_OF_MOLECULES = 0;

std::vector<std::function<void(Object*)>> GetSubscriptionsByDefault();
std::function<void(Object*)> GetDrawSubscription();
std::function<void(Object*)> GetCollisionSubscription();
std::vector<Object*> SpawnDefaultObjects(std::vector<std::function<void(Object*)>>& subscriptions_by_default);
void SpawnShell(std::vector<Object*>& objects, std::vector<std::function<void(Object*)>>& subscriptions_by_default);
void SubscribeToDefaultInteractons(Object* object_ptr, std::vector<std::function<void(Object*)>>& subscriptions_by_default);
void SpawnMolecules(std::vector<Object*>& objects, std::vector<std::function<void(Object*)>>& subscriptions_by_default);
void StepByStepSimulation(std::vector<Object*>& objects, std::vector<Interaction<Predictable>>& predictable_interactions, 
                          std::vector<Interaction<Continuus>>& continuus_interactions, time_type& global_time);
void CheckInteractions(std::vector<Interaction<Predictable>>& predictable_interactions, std::vector<Interaction<Continuus>>& continuus_interactions);
void MoveObjects(std::vector<Object*>& objects);                                        
