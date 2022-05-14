#ifndef CHECK_COLLISION_HPP
#define CHECK_COLLISION_HPP

#include "ObjectStorage.hpp"

#ifndef UNUSED
#define UNUSED(x) [&x](){};
#endif

template <typename Object>
bool CanObjectHaveCollision(const ObjectInfo<Object> object)
{
    return !((object.ContainsSpeed() == true) && (object.ContainsMass() == false));
}

template <typename Object1, typename Object2>
bool CheckCollision(const ObjectInfo<Object1> first_object, const ObjectInfo<Object2> second_object)
{
    assert(CanObjectHaveCollision(first_object));
    assert(CanObjectHaveCollision(second_object));

    auto first_object_coordinates  = first_object.GetCoordinates();
    auto second_object_coordinates = second_object.GetCoordinates();

    if (first_object.ContainsSpeed())
    {
        auto first_object_speed  = first_object.GetSpeed();

        if (second_object.ContainsSpeed())
        {
            auto second_object_speed = second_object.GetSpeed();
            return CheckCollision(first_object.GetObject(),  first_object_coordinates,  first_object_speed, 
                                  second_object.GetObject(), second_object_coordinates, second_object_speed);
        }
        else
        {
            return CheckCollision(first_object.GetObject(),  first_object_coordinates,  first_object_speed, 
                                  second_object.GetObject(), second_object_coordinates);
        }
    }
    else
    {
        if (second_object.ContainsSpeed())
        {
            auto second_object_speed = second_object.GetSpeed();
            return CheckCollision(first_object.GetObject(),  first_object_coordinates,
                                  second_object.GetObject(), second_object_coordinates, second_object_speed);
        }
        else
        {
            return CheckCollision(first_object.GetObject(),  first_object_coordinates, 
                                  second_object.GetObject(), second_object_coordinates);
        } 
    }
}

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_speed,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_speed);
bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed);
bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed);
bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  const speed_type& first_ring_speed,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_speed);

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_speed,
                    const Circle& second_circle, const object_coordinates& second_circle_center);
bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates);
bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates, const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates);
bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center, const speed_type& first_ring_speed,
                    const Ring& second_ring, const object_coordinates& second_ring_center);

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_speed);
bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                    const Ring& ring,     const object_coordinates& ring_coordinates, const speed_type& ring_speed);
bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed);
bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_speed);

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                    const Circle& second_circle, const object_coordinates& second_circle_center);
bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                    const Ring& ring,     const object_coordinates& ring_coordinates);
bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                    const Circle& circle, const object_coordinates& circle_coordinates);
bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                    const Ring& second_ring, const object_coordinates& second_ring_center);

bool IsPenetrated(const Circle& first_circle, const Circle& second_circle, const coordinate_type distance);
bool IsPenetrated(const Circle& circle, const Ring& ring, const coordinate_type distance);
bool IsPenetrated(const Ring& ring, const Circle& circle, const coordinate_type distance);

#endif /* CHECK_COLLISION_HPP */
