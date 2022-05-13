#ifndef DRAWNING_INTERACTION_HPP
#define DRAWNING_INTERACTION_HPP

#include "ObjectStorage.hpp"
#include "Interaction.hpp"
#include "IdStorage.hpp"
#include "DrawObject.hpp"
#include "UsingAliasMolecularBox.hpp"

#include "TimerAdapter/TimerInterface.hpp"

#include <optional>
#include <unordered_set>

#include <iostream>

namespace Draw
{

struct drawning_info
{
    const std::unordered_set<id_type>& objects_to_draw_;
    const color background_color_;
};

struct time_info
{
    time_type& next_drawning_time_;
    const time_type drawning_period_;
};

template<typename GraphicImplementation, typename TimerImplementation>
struct drawning_adapters
{
    GraphicInterface<GraphicImplementation>* graphic_;
    TimerInterface<TimerImplementation>* timer_;
};

template<typename GraphicImplementation, typename TimerImplementation>
class Draw
{
  private:
    const drawning_info drawning_info_;
    time_info time_info_;

    const ObjectStorage& objects_;
    const molecular_box_coordinate_system& coordinate_system_;

    const milliseconds frame_time_;

    std::optional<milliseconds> last_draw_ticks_ = std::nullopt;

    drawning_adapters<GraphicImplementation, TimerImplementation> adapters_;

  public:

    Draw() = delete;
    Draw(const drawning_info drawning_info, time_info time_info, const ObjectStorage& objects, 
         const molecular_box_coordinate_system& coordinate_system, const milliseconds frame_time,
         drawning_adapters<GraphicImplementation, TimerImplementation> adapters) :
        drawning_info_(drawning_info), time_info_(time_info), 
        objects_(objects), coordinate_system_(coordinate_system), frame_time_(frame_time),
        adapters_(adapters)
    {
    }

    void operator()()
    {
        assert(adapters_.graphic_ != nullptr);
        assert(adapters_.timer_ != nullptr);

        time_info_.next_drawning_time_ += time_info_.drawning_period_;
        adapters_.graphic_->ClearWindow(drawning_info_.background_color_);
    
        std::for_each(drawning_info_.objects_to_draw_.cbegin(), drawning_info_.objects_to_draw_.cend(), [this](const auto id){

            auto object = objects_.GetObject(id);
            auto relative_object_coordinates = objects_.GetCoordinates(id);
            color object_color = objects_.GetColor(id);

            DrawObject(adapters_.graphic_, coordinate_system_, object, relative_object_coordinates, object_color);    
        });

        adapters_.graphic_->Refresh();

        auto current_ticks = adapters_.timer_->GetTicks();

        if (last_draw_ticks_.has_value())
        {
            if (last_draw_ticks_.value() + frame_time_ >= current_ticks)
            {
                adapters_.timer_->Delay(last_draw_ticks_.value() + frame_time_ - current_ticks);
                last_draw_ticks_.value() += frame_time_;
            }
            else
            {
                //TODO: user shouldn't see this message, logging is needed
                //TODO: for user to see that kind of problem FPS counter is needed
                std::cout << "FPS downfall is detected on " << current_ticks << " ticks" << std::endl;
                last_draw_ticks_.value() = current_ticks;
            }
        }
        else
        {
            last_draw_ticks_ = current_ticks;
        }
    }
};

} /* namespace Draw */

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

namespace DrawningInteraction
{

struct time_info
{
    const time_type& global_time_;
    time_type next_drawning_time_;
    const time_type drawning_period_;
};

template<typename GraphicImplementation, typename TimerImplementation>
using drawning_adapters = Draw::drawning_adapters<GraphicImplementation, TimerImplementation>;

class DrawningInteraction: public PredictableInteraction
{
  private:
    std::unordered_set<id_type> objects_to_draw_;
    time_type next_drawning_time_;

  public:
    DrawningInteraction() = delete;

    template<typename GraphicImplementation, typename TimerImplementation>
    DrawningInteraction(const time_info time_info, const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system,
                        const color background_color, const milliseconds frame_time, drawning_adapters<GraphicImplementation, TimerImplementation> adapters) :
        PredictableInteraction(Draw::Draw<GraphicImplementation, TimerImplementation>({objects_to_draw_, background_color}, 
                                                                                      {next_drawning_time_, time_info.drawning_period_}, 
                                                                                      objects, coordinate_system, frame_time, adapters), 
                               GetTimeToNextDrawning(time_info.global_time_, next_drawning_time_)), 
        next_drawning_time_(time_info.next_drawning_time_)
    {
    }

    void AddObjectToDraw(id_type id);

    void DeleteObjectToDraw(id_type id);
};

} /* namespace DrawningInteraction */

#endif /* DRAWNING_INTERACTION_HPP */
