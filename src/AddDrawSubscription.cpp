#include <AddDrawSubscription.hpp>

AddDrawSubscription::AddDrawSubscription(const ObjectStorage& objects, IdStorage<Interaction>& interactions, 
                                         const molecular_box_coordinate_system& coordinate_system, 
                                         const time_type& current_time, time_type& next_drawning_time, const time_type drawning_period) :
    objects_(objects), interactions_(interactions), coordinate_system_(coordinate_system), current_time_(current_time), 
    next_drawning_time_(next_drawning_time), drawning_period_(drawning_period)
{
}

void AddDrawSubscription::operator()(id_type id)
{
    interactions_.AddElement(Interaction(GetDrawAction(objects_, coordinate_system_, next_drawning_time_, drawning_period_, id), 
                                         GetDrawCheck(current_time_, next_drawning_time_, drawning_period_)));
}

std::function<void()> GetDrawAction(const ObjectStorage& objects, const molecular_box_coordinate_system& coordinate_system, 
                                    time_type& next_drawning_time, const time_type drawning_period, id_type id)
{
    return [&objects, &coordinate_system, &next_drawning_time, drawning_period, id]() { 
        next_drawning_time += drawning_period;

        auto object = objects.GetObject(id);
        auto relative_object_coordinates = objects.GetCoordinates(id);
        color object_color = objects.GetColor(id);

        DrawObject(GetGraphic(), coordinate_system, object, relative_object_coordinates, object_color);
    };
}

std::function<bool()> GetDrawCheck(const time_type& current_time, time_type& next_drawning_time, const time_type drawning_period)
{
    return [&current_time, &next_drawning_time, drawning_period]() {
        assert(current_time < next_drawning_time + drawning_period);

        if (current_time < next_drawning_time)
        {
            return false;
        }


        return true;
    };
}