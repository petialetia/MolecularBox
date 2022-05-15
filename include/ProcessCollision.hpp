#ifndef PROCESS_COLLISION_HPP
#define PROCESS_COLLISION_HPP

#include "ObjectStorage.hpp"
#include "CheckCollision.hpp"

template <typename Object1, typename Object2>
void ProcessCollision(ObjectInfo<Object1> first_object, ObjectInfo<Object2> second_object)
{
    assert(CanObjectHaveCollision(first_object));
    assert(CanObjectHaveCollision(second_object));

    if (first_object.ContainsSpeed())
    {
        if (second_object.ContainsSpeed())
        {
            ProcessCollisionBothWithSpeed(first_object, second_object);
        }
        else
        {
            ProcessCollisionFirstWithSpeed(first_object, second_object);
        }
    }
    else
    {
        if (second_object.ContainsSpeed())
        {
            ProcessCollisionSecondWithSpeed(first_object, second_object);
        }
        else
        {
            ProcessCollisionWithoutSpeed(first_object, second_object);
        } 
    }
}

void ProcessCollisionBothWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle);
void ProcessCollisionBothWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring);
void ProcessCollisionBothWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle);
void ProcessCollisionBothWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring);

void ProcessCollisionFirstWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle);
void ProcessCollisionFirstWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring);
void ProcessCollisionFirstWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle);
void ProcessCollisionFirstWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring);

void ProcessCollisionSecondWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle);
void ProcessCollisionSecondWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring);
void ProcessCollisionSecondWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle);
void ProcessCollisionSecondWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring);

void ProcessCollisionWithoutSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle);
void ProcessCollisionWithoutSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring);
void ProcessCollisionWithoutSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle);
void ProcessCollisionWithoutSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring);

#endif /* PROCESS_COLLISION_HPP */
