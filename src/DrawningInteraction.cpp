#include <DrawningInteraction.hpp>

GetTimeToNextDrawning::GetTimeToNextDrawning(const time_type& global_time, const time_type& next_drawning_time) :
    global_time_(global_time), next_drawning_time_(next_drawning_time)
{
}

time_type GetTimeToNextDrawning::operator()()
{
    assert(next_drawning_time_ >= global_time_);

    return next_drawning_time_ - global_time_;
}

namespace DrawningInteraction
{

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

} /* namespace DrawningInteraction */