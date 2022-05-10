#ifndef OBJECT_STORAGE_HPP
#define OBJECT_STORAGE_HPP

#include "Coordinates.hpp"
#include "Shape.hpp"
#include "IdStorage.hpp"

#include <variant>
#include <vector>
#include <unordered_map>

using object_coordinates = Coordinates<coordinate_type>;
using offset_type = object_coordinates;

using object = std::variant<Ring, Circle>;
using speed_type = object_coordinates;

using coordinate_storage = std::unordered_map<id_type, object_coordinates>;
using color_storage = std::unordered_map<id_type, color>;
using speed_storage = std::unordered_map<id_type, speed_type>;

class ObjectStorage
{
  private:
    IdStorage<object> objects_ {};
    coordinate_storage object_coordinates_ {};
    color_storage object_colors_ {};
    speed_storage object_speeds_ {};

  public:
    explicit ObjectStorage() = default;

    ObjectStorage(const ObjectStorage&) = delete;
    ObjectStorage(ObjectStorage&) = delete;

    ObjectStorage& operator=(const ObjectStorage&) = delete;
    ObjectStorage& operator=(ObjectStorage&) = delete;

    id_type AddObject(object&& object, object_coordinates coordinates, color color);
    id_type AddObject(object&& object, object_coordinates coordinates, color color, speed_type speed);

    object& GetObject(id_type id);
    const object& GetObject(id_type id) const;

    object_coordinates& GetCoordinates(id_type id);
    const object_coordinates& GetCoordinates(id_type id) const;

    color& GetColor(id_type id);
    const color GetColor(id_type id) const;

    bool ContainsSpeed(id_type id) const;
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


    auto colors_begin()
    {
        return object_colors_.begin();
    }

    auto colors_cbegin() const
    {
        return object_colors_.cbegin();
    }


    auto colors_end()
    {
        return object_colors_.end();
    }

    auto colors_cend() const
    {
        return object_colors_.cend();
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

#define ImplementGet(property)                    \
    const auto& Get##property() const             \
    {                                             \
        return object_storage_.Get##property(id_);\
    }                                             \
                                                  \
    auto& Get##property()                         \
    {                                             \
        return object_storage_.Get##property(id_);\
    }

#define ImplementContains(property)                    \
    bool Contains##property() const                    \
    {                                                  \
        return object_storage_.Contains##property(id_);\
    }

template<typename Object>
class ObjectInfo
{
  private:
    Object& object_;
    const id_type id_;
    ObjectStorage& object_storage_;

  public:
    ObjectInfo() = delete;
    
    explicit ObjectInfo(Object& object, id_type id, ObjectStorage& object_storage) :
        object_(object), id_(id), object_storage_(object_storage)
    {
    }

    Object& GetObject()
    {
        return object_;
    }

    const Object& GetObject() const
    {
        return object_;
    }

    id_type GetId() const
    {
        return id_;
    }

    ImplementGet(Coordinates)
    ImplementGet(Color)
    ImplementGet(Speed)

    ImplementContains(Speed)
};

#undef ImplementGet
#undef ImplementContains

#endif /* OBJECT_STORAGE_HPP */
