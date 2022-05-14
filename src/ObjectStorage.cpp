#include <ObjectStorage.hpp>

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color)
{
    auto new_object_id = objects_.AddElement(std::move(object));

    object_coordinates_[new_object_id] = coordinates;
    object_colors_[new_object_id] = color;

    return new_object_id;
}

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color, mass_type mass)
{
    auto new_object_id = AddObject(std::move(object), coordinates, color);

    SpecifyMass(new_object_id, mass);

    return new_object_id;
}

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color, speed_type speed)
{
    auto new_object_id = AddObject(std::move(object), coordinates, color);

    SpecifySpeed(new_object_id, speed);

    return new_object_id;
}

id_type ObjectStorage::AddObject(object&& object, object_coordinates coordinates, color color, mass_type mass, speed_type speed)
{
    auto new_object_id = AddObject(std::move(object), coordinates, color);

    SpecifyMass(new_object_id, mass);
    SpecifySpeed(new_object_id, speed);

    return new_object_id;
}

object& ObjectStorage::GetObject(id_type id)
{
    assert(objects_.contains(id));
    return objects_.at(id);
}

const object& ObjectStorage::GetObject(id_type id) const
{
    assert(objects_.contains(id));
    return objects_.at(id);
}

object_coordinates& ObjectStorage::GetCoordinates(id_type id)
{
    assert(object_coordinates_.contains(id));
    return object_coordinates_.at(id);
}

const object_coordinates& ObjectStorage::GetCoordinates(id_type id) const
{
    assert(object_coordinates_.contains(id));
    return object_coordinates_.at(id);
}

color& ObjectStorage::GetColor(id_type id)
{
    assert(object_colors_.contains(id));
    return object_colors_.at(id);
}

const color ObjectStorage::GetColor(id_type id) const
{
    assert(object_colors_.contains(id));
    return object_colors_.at(id);
}

void ObjectStorage::SpecifyMass(id_type id, mass_type mass)
{
    object_masses_[id] = mass;
}

bool ObjectStorage::ContainsMass(id_type id) const
{
    return object_masses_.contains(id);
}

mass_type& ObjectStorage::GetMass(id_type id)
{
    assert(object_masses_.contains(id));
    return object_masses_.at(id);
}

mass_type ObjectStorage::GetMass(id_type id) const
{
    assert(object_masses_.contains(id));
    return object_masses_.at(id);
}

void ObjectStorage::SpecifySpeed(id_type id, speed_type speed)
{
    object_speeds_[id] = speed;
}

bool ObjectStorage::ContainsSpeed(id_type id) const
{
    return object_speeds_.contains(id);
}

speed_type& ObjectStorage::GetSpeed(id_type id)
{
    assert(object_speeds_.contains(id));
    return object_speeds_.at(id);
}

const speed_type& ObjectStorage::GetSpeed(id_type id) const
{
    assert(object_speeds_.contains(id));
    return object_speeds_.at(id);
}