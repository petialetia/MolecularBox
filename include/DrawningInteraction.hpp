#ifndef DRAWNING_INTERACTION_HPP
#define DRAWNING_INTERACTION_HPP

#include "ObjectStorage.hpp"
#include "Interaction.hpp"
#include "IdStorage.hpp"
#include "DrawObject.hpp"
#include "UsingAliasMolecularBox.hpp"

#include "TimerAdapter/TimerInterface.hpp"

#include <unordered_set>

template<typename GraphicImplementation, typename TimerImplementation>
class Draw
{
  private:
    time_type& next_drawning_time_;
    const time_type drawning_period_;
    const std::unordered_set<id_type>& objects_to_draw_;
    const ObjectStorage& objects_;
    const molecular_box_coordinate_system& coordinate_system_;
    const color background_color_;

    GraphicInterface<GraphicImplementation>* graphic_;

    TimerInterface<TimerImplementation>* timer_;
    const milliseconds delay_;

  public:
    Draw() = delete;
    Draw(time_type& next_drawning_time, const time_type drawning_period, const std::unordered_set<id_type>& objects_to_draw, 
         const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, const color background_color,
         GraphicInterface<GraphicImplementation>* graphic, TimerInterface<TimerImplementation>* timer, milliseconds delay) :
        next_drawning_time_(next_drawning_time), drawning_period_(drawning_period), objects_to_draw_(objects_to_draw), objects_(objects), 
        coordinate_system_(coordinate_system), background_color_(background_color), graphic_(graphic), timer_(timer), delay_(delay)
    {
    }

    void operator()()
    {
        //TODO: Rewrite with Timer

        assert(graphic_ != nullptr);
        assert(timer_ != nullptr);

        next_drawning_time_ += drawning_period_;
        graphic_->ClearWindow(background_color_);
    
        std::for_each(objects_to_draw_.cbegin(), objects_to_draw_.cend(), [this](const auto id){

            auto object = objects_.GetObject(id);
            auto relative_object_coordinates = objects_.GetCoordinates(id);
            color object_color = objects_.GetColor(id);

            DrawObject(graphic_, coordinate_system_, object, relative_object_coordinates, object_color);    
        });

        graphic_->Refresh();

        timer_->Delay(delay_);
    }
};

class GetTimeToNextDrawning
{
  private:
    const time_type& global_time_;
    const time_type& next_drawning_time_;

  public:
    GetTimeToNextDrawning() = delete;
    GetTimeToNextDrawning(const time_type& global_time, const time_type& next_drawning_time);
    
    time_type operator()();
};

class DrawningInteraction: public PredictableInteraction
{
  private:
    std::unordered_set<id_type> objects_to_draw_;
    time_type next_drawning_time_;

  public:
    DrawningInteraction() = delete;

    template<typename GraphicImplementation, typename TimerImplementation>
    DrawningInteraction(const time_type& global_time, const time_type next_drawning_time, const time_type drawning_period,
                        const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                        const color background_color, GraphicInterface<GraphicImplementation>* graphic,
                        TimerInterface<TimerImplementation>* timer, milliseconds delay) :
        PredictableInteraction(Draw<GraphicImplementation, TimerImplementation>(next_drawning_time_, drawning_period, objects_to_draw_, objects, 
                                                                                coordinate_system, background_color, graphic, timer, delay), 
                               GetTimeToNextDrawning(global_time, next_drawning_time_)), 
        next_drawning_time_(next_drawning_time)
    {
    }

    void AddObjectToDraw(id_type id);

    void DeleteObjectToDraw(id_type id);
};

#endif /* DRAWNING_INTERACTION_HPP */
