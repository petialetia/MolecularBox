#include <ObjectStorage.hpp>

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color)
{
    auto new_object_id = objects_.AddElement(std::move(object));

    object_coordinates_[new_object_id] = coordinates;
    object_colors_[new_object_id] = color;

    return new_object_id;
}

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color, speed_type speed)
{
    auto new_object_id = AddObject(std::move(object), coordinates, color);

    object_speeds_[new_object_id] = speed;

    return new_object_id;
}

object& ObjectStorage::GetObject(id_type id)
{
    return objects_.at(id);
}

const object& ObjectStorage::GetObject(id_type id) const
{
    return objects_.at(id);
}

object_coordinates& ObjectStorage::GetCoordinates(id_type id)
{
    return object_coordinates_.at(id);
}

const object_coordinates& ObjectStorage::GetCoordinates(id_type id) const
{
    return object_coordinates_.at(id);
}

color& ObjectStorage::GetColor(id_type id)
{
    return object_colors_.at(id);
}

const color ObjectStorage::GetColor(id_type id) const
{
    return object_colors_.at(id);
}

speed_type& ObjectStorage::GetSpeed(id_type id)
{
    return object_speeds_.at(id);
}

const speed_type& ObjectStorage::GetSpeed(id_type id) const
{
    return object_speeds_.at(id);
}