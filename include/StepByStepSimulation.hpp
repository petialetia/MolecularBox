#ifndef STEP_BY_STEP_SIMULATION_HPP
#define STEP_BY_STEP_SIMULATION_HPP

#include "ObjectStorage.hpp"
#include "InteractionStorage.hpp"

#include "TimerAdapter/SDL2TimerFunctions.hpp"
#include "TimerAdapter/SDL2TimerImplementation.hpp"

using subsription_storage = std::vector<std::function<void(id_type)>>;
                                
void MoveObjects(ObjectStorage& objects, time_type time);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset); 


class StepByStepSimulation
{
  private:
    time_type global_time_ = 0;
    const time_type time_step_ = 0;
    molecular_box_coordinate_system coordinate_system_;

    ObjectStorage object_storage_;
    InteractionStorage interaction_storage_;

    subsription_storage subscriptions_by_default_;

  public:

    StepByStepSimulation() = delete;

    template<typename GraphicImplementation, typename TimerImplementation>
    StepByStepSimulation(time_type time_step, molecular_box_coordinate_system coordinate_system, 
                         time_type drawning_period, color background_color, milliseconds frame_time,
                         DrawningInteraction::drawning_adapters<GraphicImplementation, TimerImplementation> adapters) :
      time_step_(time_step),
      coordinate_system_(coordinate_system),
      interaction_storage_({global_time_, 0, drawning_period}, object_storage_, coordinate_system_, background_color, frame_time, adapters)
    {
    }

    const time_type& GetGlobalTime();
    ObjectStorage& GetObjects();
    InteractionStorage& GetInteractions();

    void AddSubscriptionByDefault(std::function<void(id_type)> subscription);
    void SubscribeToDefaultInteraction(id_type id);

    template<typename... Args>
    void AddObjectWithDefaultSubscriptions(Args... args)
    {
        auto new_object_id = object_storage_.AddObject(args...);
        SubscribeToDefaultInteraction(new_object_id);
    }

    void CheckInteractions();
    void Step();
};

#endif /* STEP_BY_STEP_SIMULATION_HPP */
