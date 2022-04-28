#include <DrawningInteraction.hpp>

DrawningInteraction::DrawningInteraction(const time_type& global_time, const time_type next_drawning_time, const time_type drawning_period,
                                         const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                                         const color background_color) :
    PredictableInteraction(Draw(next_drawning_time_, drawning_period, objects_to_draw_, objects, coordinate_system, background_color), 
                           GetTimeToNextDrawning(global_time, next_drawning_time_)), 
    next_drawning_time_(next_drawning_time)
{
}

void DrawningInteraction::AddObjectToDraw(id_type id)
{
    assert(!objects_to_draw_.contains(id));
    objects_to_draw_.insert(id);
}

void DrawningInteraction::DeleteObjectToDraw(id_type id)
{
    assert(objects_to_draw_.contains(id));
    objects_to_draw_.erase(id);
}


Draw::Draw(time_type& next_drawning_time, const time_type drawning_period, const std::unordered_set<id_type>& objects_to_draw, 
           const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, const color background_color) :
    next_drawning_time_(next_drawning_time), drawning_period_(drawning_period), objects_to_draw_(objects_to_draw), 
    objects_(objects), coordinate_system_(coordinate_system), background_color_(background_color)
{
}

void Draw::operator()()
{
    next_drawning_time_ += drawning_period_;
    GetGraphic()->ClearWindow(background_color_);
    
    std::for_each(objects_to_draw_.cbegin(), objects_to_draw_.cend(), [this](const auto id){

        auto object = objects_.GetObject(id);
        auto relative_object_coordinates = objects_.GetCoordinates(id);
        color object_color = objects_.GetColor(id);

        DrawObject(GetGraphic(), coordinate_system_, object, relative_object_coordinates, object_color);    
    });

    GetGraphic()->Refresh();
}

GetTimeToNextDrawning::GetTimeToNextDrawning(const time_type& global_time, const time_type& next_drawning_time) :
    global_time_(global_time), next_drawning_time_(next_drawning_time)
{
}

time_type GetTimeToNextDrawning::operator()()
{
    //std::cout << next_drawning_time_ << " f " << global_time_ << std::endl;

    assert(next_drawning_time_ >= global_time_);

    return next_drawning_time_ - global_time_;
}