#include <include/ObjectStorage.hpp>

id_type ObjectStorage::AddObject(object&& object, coordinates coordinates)
{
    auto new_object_id = objects_.AddElement(std::move(object));

    object_coordinates_[new_object_id] = coordinates;

    return new_object_id;
}

id_type ObjectStorage::AddObject(object&& object, coordinates coordinates, speed_type speed)
{
    auto new_object_id = AddObject(std::move(object), coordinates);

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

coordinates& ObjectStorage::GetCoordinates(id_type id)
{
    return object_coordinates_.at(id);
}

const coordinates& ObjectStorage::GetCoordinates(id_type id) const
{
    return object_coordinates_.at(id);
}

speed_type& ObjectStorage::GetSpeed(id_type id)
{
    return object_speeds_.at(id);
}

const speed_type& ObjectStorage::GetSpeed(id_type id) const
{
    return object_speeds_.at(id);
}