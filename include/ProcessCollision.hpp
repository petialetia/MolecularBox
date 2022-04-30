#ifndef PROCESS_COLLISION_HPP
#define PROCESS_COLLISION_HPP

#include "ObjectStorage.hpp"

#ifndef UNUSED
#define UNUSED(x) [&x](){};
#endif

template <typename Object1, typename Object2>
void ProcessCollision(const id_type first_id, Object1 first_object, const id_type second_id, Object2 second_object, ObjectStorage& objects)
{
    auto first_object_coordinates  = objects.GetCoordinates(first_id);
    auto second_object_coordinates = objects.GetCoordinates(second_id);

    if (objects.ContainsSpeed(first_id))
    {
        auto& first_object_speed  = objects.GetSpeed(first_id);

        if (objects.ContainsSpeed(second_id))
        {
            auto& second_object_speed = objects.GetSpeed(second_id);
            ProcessCollision(first_object,  first_object_coordinates,  first_object_speed, 
                             second_object, second_object_coordinates, second_object_speed);
        }
        else
        {
            ProcessCollision(first_object,  first_object_coordinates,  first_object_speed, 
                             second_object, second_object_coordinates);
        }
    }
    else
    {
        if (objects.ContainsSpeed(second_id))
        {
            auto second_object_speed = objects.GetSpeed(second_id);
            ProcessCollision(first_object,  first_object_coordinates,
                             second_object, second_object_coordinates, second_object_speed);
        }
        else
        {
            ProcessCollision(first_object,  first_object_coordinates, 
                             second_object, second_object_coordinates);
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
