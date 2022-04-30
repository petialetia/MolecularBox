#ifndef CHECK_COLLISION_HPP
#define CHECK_COLLISION_HPP

#include "ObjectStorage.hpp"
#include <optional>

#ifndef UNUSED
#define UNUSED(x) [&x](){};
#endif

template <typename Object1, typename Object2>
bool CheckCollision(const id_type first_id, Object1 first_object, const id_type second_id, Object2 second_object, const ObjectStorage& objects)
{
    auto first_object_coordinates  = objects.GetCoordinates(first_id);
    auto second_object_coordinates = objects.GetCoordinates(second_id);

    if (objects.ContainsSpeed(first_id))
    {
        auto first_object_speed  = objects.GetSpeed(first_id);

        if (objects.ContainsSpeed(second_id))
        {
            auto second_object_speed = objects.GetSpeed(second_id);
            return CheckCollision(first_object,  first_object_coordinates,  first_object_speed, 
                                  second_object, second_object_coordinates, second_object_speed);
        }
        else
        {
            return CheckCollision(first_object,  first_object_coordinates,  first_object_speed, 
                                  second_object, second_object_coordinates);
        }
    }
    else
    {
        if (objects.ContainsSpeed(second_id))
        {
            auto second_object_speed = objects.GetSpeed(second_id);
            return CheckCollision(first_object,  first_object_coordinates, 
                                  second_object, second_object_coordinates, second_object_speed);
        }
        else
        {
            return CheckCollision(first_object,  first_object_coordinates, 
                                  second_object, second_object_coordinates);
        } 
    }
}

template <typename Object1, typename Object2>
bool CheckCollision(Object1 first_object,  const object_coordinates& first_object_cordiantes, const speed_type& first_object_spped,
                    Object2 second_object, const object_coordinates& second_object_cordiantes)
{
    //TODO: Imlement

    UNUSED(first_object)
    UNUSED(first_object_cordiantes)
    UNUSED(first_object_spped)
    UNUSED(second_object)
    UNUSED(second_object_cordiantes)

    assert(false);
    return false;
}

template <typename Object1, typename Object2>
bool CheckCollision(Object1 first_object,  const object_coordinates& first_object_cordiantes,
                    Object2 second_object, const object_coordinates& second_object_cordiantes, const speed_type& second_object_spped)
{
    //TODO: Imlement

    UNUSED(first_object)
    UNUSED(first_object_cordiantes)
    UNUSED(second_object)
    UNUSED(second_object_cordiantes)
    UNUSED(second_object_spped)

    assert(false);
    return false;
}

template <typename Object1, typename Object2>
bool CheckCollision(Object1 first_object,  const object_coordinates& first_object_cordiantes,
                    Object2 second_object, const object_coordinates& second_object_cordiantes)
{
    //TODO: Imlement

    UNUSED(first_object)
    UNUSED(first_object_cordiantes)
    UNUSED(second_object)
    UNUSED(second_object_cordiantes)

    assert(false);
    return false;
}

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_spped,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_spped);

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed);

bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed);

bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  const speed_type& first_ring_spped,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_spped);

bool IsPenetrated(const Circle& first_circle, const Circle& second_circle, const coordinate_type distance);
bool IsPenetrated(const Circle& circle, const Ring& ring, const coordinate_type distance);
bool IsPenetrated(const Ring& ring, const Circle& circle, const coordinate_type distance);

#endif /* CHECK_COLLISION_HPP */
