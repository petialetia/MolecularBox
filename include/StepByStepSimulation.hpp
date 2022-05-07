#ifndef STEP_BY_STEP_SIMULATION_HPP
#define STEP_BY_STEP_SIMULATION_HPP

#include "ObjectStorage.hpp"
#include "InteractionStorage.hpp"

#include "TimerAdapter/SDL2TimerFunctions.hpp"
#include "TimerAdapter/SDL2TimerImplementation.hpp"

using subsription_storage = std::vector<std::function<void(id_type)>>;

const time_type TIME_STEP = 1.0/2048;

const time_type DRAWNING_PERIOD_BY_DEFAULT = 1.0/4;

const color BACKGROUND_COLOR = {.red = 0,
                                .green = 0,
                                .blue = 0,
                                .alpha = 0};
                                
void MoveObjects(ObjectStorage& objects, time_type time);    
offset_type CalculateOffset(speed_type speed, time_type time);
void MoveOnOffset(object_coordinates& object_coordinates, offset_type offset); 

template<typename TimetImplementation>
class StepByStepSimulation
{
  private:
    time_type global_time_ = 0;
    molecular_box_coordinate_system coordinate_system_;

    ObjectStorage object_storage_;
    InteractionStorage interaction_storage_;

    subsription_storage subscriptions_by_default_;

  public:

    StepByStepSimulation() = delete;
    StepByStepSimulation(molecular_box_coordinate_system coordinate_system) :
      coordinate_system_(coordinate_system), 
      interaction_storage_(global_time_, 0, DRAWNING_PERIOD_BY_DEFAULT, object_storage_, coordinate_system_, BACKGROUND_COLOR)
    {
    }

    ObjectStorage& GetObjects()
    {
        return object_storage_;
    }

    InteractionStorage& GetInteractions()
    {
        return interaction_storage_;
    }


    void AddSubscriptionByDefault(std::function<void(id_type)> subscription)
    {
        subscriptions_by_default_.push_back(subscription);
    }

    void SubscribeToDefaultInteraction(id_type id)
    {
        for (auto& AddSubscription : subscriptions_by_default_)
        {
            AddSubscription(id);
        }
    }


    template<typename... Args>
    void AddObjectWithDefaultSubscriptions(Args... args)
    {
        auto new_object_id = object_storage_.AddObject(args...);
        SubscribeToDefaultInteraction(new_object_id);
    }

    void TryDraw()
    {
        interaction_storage_.TryDraw();
    }

    void Step()
    {
        MoveObjects(object_storage_, TIME_STEP);
        global_time_+= TIME_STEP;

        interaction_storage_.CheckInteractions();
    }
};

#endif /* STEP_BY_STEP_SIMULATION_HPP */
