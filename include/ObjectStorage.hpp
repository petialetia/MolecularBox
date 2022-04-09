#ifndef OBJECT_STORAGE_HPP
#define OBJECT_STORAGE_HPP

#include <include/Coordinates.hpp>
#include <include/Shape.hpp>
#include <include/IdStorage.hpp>

#include <variant>
#include <vector>
#include <unordered_map>

using ObjectCoordinates = Coordinates<coordinate_type>;
using coordinates = ObjectCoordinates;
using offset_type = ObjectCoordinates;

using object = std::variant<Circle>;
using speed_type = std::vector<coordinate_type>;

using coordinate_storage = std::unordered_map<id_type, coordinates>;
using speed_storage = std::unordered_map<id_type, speed_type>;

class ObjectStorage
{
  private:
    IdStorage<object> objects_ {};
    coordinate_storage object_coordinates_ {};
    speed_storage object_speeds_ {};

  public:
    explicit ObjectStorage() = default;

    ObjectStorage(const ObjectStorage&) = delete;
    ObjectStorage(ObjectStorage&) = delete;

    ObjectStorage& operator=(const ObjectStorage&) = delete;
    ObjectStorage& operator=(ObjectStorage&) = delete;

    id_type AddObject(object&& object, coordinates coordinates);
    id_type AddObject(object&& object, coordinates coordinates, speed_type speed);

    object& GetObject(id_type id);
    const object& GetObject(id_type id) const;

    coordinates& GetCoordinates(id_type id);
    const coordinates& GetCoordinates(id_type id) const; 

    speed_type& GetSpeed(id_type id);
    const speed_type& GetSpeed(id_type id) const;

    auto objects_begin()
    {
        return objects_.begin();
    }

    auto objects_cbegin() const
    {
        return objects_.cbegin();
    }


    auto objects_end()
    {
        return objects_.end();
    }

    auto objects_cend() const
    {
        return objects_.cend();
    }


    auto coordinates_begin()
    {
        return object_coordinates_.begin();
    }

    auto coordinates_cbegin() const
    {
        return object_coordinates_.cbegin();
    }


    auto coordinates_end()
    {
        return object_coordinates_.end();
    }

    auto coordinates_cend() const
    {
        return object_coordinates_.cend();
    }


    auto speeds_begin()
    {
        return object_speeds_.begin();
    }

    auto speeds_cbegin() const
    {
      return object_speeds_.cbegin();
    }


    auto speeds_end()
    {
        return object_speeds_.end();
    }

    auto speeds_cend() const
    {
      return object_speeds_.cend();
    }
};

#endif /* OBJECT_STORAGE_HPP */
