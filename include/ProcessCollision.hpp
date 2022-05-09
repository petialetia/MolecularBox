#ifndef PROCESS_COLLISION_HPP
#define PROCESS_COLLISION_HPP

#include "ObjectStorage.hpp"

#ifndef UNUSED
#define UNUSED(x) [&x](){};
#endif

template <typename Object1, typename Object2>
void ProcessCollision(ObjectInfo<Object1> first_object, ObjectInfo<Object2> second_object)
{
    auto first_object_coordinates  = first_object.GetCoordinates();
    auto second_object_coordinates = second_object.GetCoordinates();

    if (first_object.ContainsSpeed())
    {
        auto& first_object_speed  = first_object.GetSpeed();

        if (second_object.ContainsSpeed())
        {
            auto& second_object_speed = second_object.GetSpeed();
            ProcessCollision(first_object.GetObject(),  first_object_coordinates,  first_object_speed, 
                             second_object.GetObject(), second_object_coordinates, second_object_speed);
        }
        else
        {
            ProcessCollision(first_object.GetObject(),  first_object_coordinates,  first_object_speed, 
                             second_object.GetObject(), second_object_coordinates);
        }
    }
    else
    {
        if (second_object.ContainsSpeed())
        {
            auto second_object_speed = second_object.GetSpeed();
            ProcessCollision(first_object.GetObject(),  first_object_coordinates,
                             second_object.GetObject(), second_object_coordinates, second_object_speed);
        }
        else
        {
            ProcessCollision(first_object.GetObject(),  first_object_coordinates, 
                             second_object.GetObject(), second_object_coordinates);
        } 
    }
}

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  speed_type& first_circle_speed,
                      const Circle& second_circle, const object_coordinates& second_circle_center, speed_type& second_circle_speed);
void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed,
                      const Ring& ring,     const object_coordinates& ring_coordinates,   speed_type& ring_speed);
void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   speed_type& ring_speed,
                      const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed);
void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  speed_type& first_ring_speed,
                      const Ring& second_ring, const object_coordinates& second_ring_center, speed_type& second_ring_speed);

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center, speed_type& first_circle_speed,
                      const Circle& second_circle, const object_coordinates& second_circle_center);
void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed,
                      const Ring& ring,     const object_coordinates& ring_coordinates);
void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates, speed_type& ring_speed,
                      const Circle& circle, const object_coordinates& circle_coordinates);
void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center, speed_type& first_ring_speed,
                      const Ring& second_ring, const object_coordinates& second_ring_center);

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                      const Circle& second_circle, const object_coordinates& second_circle_center, speed_type& second_circle_speed);
void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                      const Ring& ring,     const object_coordinates& ring_coordinates, speed_type& ring_speed);
void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                      const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed);
void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                      const Ring& second_ring, const object_coordinates& second_ring_center, speed_type& second_ring_speed);

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                      const Circle& second_circle, const object_coordinates& second_circle_center);
void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                      const Ring& ring,     const object_coordinates& ring_coordinates);
void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                      const Circle& circle, const object_coordinates& circle_coordinates);
void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                      const Ring& second_ring, const object_coordinates& second_ring_center);

#endif /* PROCESS_COLLISION_HPP */
