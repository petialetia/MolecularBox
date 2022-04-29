#ifndef DRAWNING_INTERACTION_HPP
#define DRAWNING_INTERACTION_HPP

#include "ObjectStorage.hpp"
#include "Interaction.hpp"
#include "IdStorage.hpp"
#include "DrawObject.hpp"
#include "GetGraphic.hpp"
#include "UsingAliasMolecularBox.hpp"

#include <unordered_set>

class DrawningInteraction: public PredictableInteraction
{
  private:
    std::unordered_set<id_type> objects_to_draw_;
    time_type next_drawning_time_;

  public:
    DrawningInteraction() = delete;
    DrawningInteraction(const time_type& global_time, const time_type next_drawning_time, const time_type drawning_period,
                        const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                        const color background_color);

    void AddObjectToDraw(id_type id);

    void DeleteObjectToDraw(id_type id);
};

class Draw
{
  private:
    time_type& next_drawning_time_;
    const time_type drawning_period_;
    const std::unordered_set<id_type>& objects_to_draw_;
    const ObjectStorage& objects_;
    const molecular_box_coordinate_system& coordinate_system_;
    const color background_color_;

  public:
    Draw() = delete;
    Draw(time_type& next_drawning_time, const time_type drawning_period, const std::unordered_set<id_type>& objects_to_draw, 
         const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, const color background_color);

    void operator()();
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

#endif /* DRAWNING_INTERACTION_HPP */
