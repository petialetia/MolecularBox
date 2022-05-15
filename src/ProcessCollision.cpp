#include <ProcessCollision.hpp>

void ProcessCollisionBothWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle)
{
    assert(first_circle.ContainsSpeed());
    assert(first_circle.ContainsMass());
    assert(second_circle.ContainsSpeed());
    assert(second_circle.ContainsMass());

    auto distance_vector = second_circle.GetCoordinates() - first_circle.GetCoordinates();

    auto first_circle_speed_projection =  CountProjection(object_coordinates(first_circle.GetSpeed()),  distance_vector);
    auto second_circle_speed_projection = CountProjection(object_coordinates(second_circle.GetSpeed()), distance_vector);

    auto first_circle_mass  = first_circle.GetMass();
    auto second_circle_mass = second_circle.GetMass();

    first_circle.GetSpeed() -= first_circle_speed_projection;
    first_circle.GetSpeed() += ((first_circle_mass - second_circle_mass) * first_circle_speed_projection + 
                               2 * second_circle_mass * second_circle_speed_projection) / 
                               (first_circle_mass + second_circle_mass);

    second_circle.GetSpeed() -= second_circle_speed_projection;
    second_circle.GetSpeed() += ((second_circle_mass - first_circle_mass) * second_circle_speed_projection +
                                2 * first_circle_mass * first_circle_speed_projection) /
                                (first_circle_mass + second_circle_mass);
}

void ProcessCollisionBothWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring)
{
    assert(circle.ContainsSpeed());
    assert(circle.ContainsMass());
    assert(ring.ContainsSpeed());
    assert(ring.ContainsMass());

    auto distance_vector = ring.GetCoordinates() - circle.GetCoordinates();
    auto distance = CountLength(distance_vector);

    if (distance >= ring.GetObject().GetInnerRadius() + ring.GetObject().GetWidth() / 2)
    {
        //TODO: implement outter collision
        assert(false);
    }


    //TODO: implement inner collision
    assert(false);
}

void ProcessCollisionBothWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle)
{
    ProcessCollisionBothWithSpeed(circle, ring);
}

void ProcessCollisionBothWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring)
{
    //TODO: implement
    assert(first_ring.ContainsSpeed());
    assert(first_ring.ContainsMass());
    assert(second_ring.ContainsSpeed());
    assert(second_ring.ContainsMass());

    assert(false);
}

void ProcessCollisionFirstWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle)
{
    //TODO: implement
    assert(first_circle.ContainsSpeed());
    assert(first_circle.ContainsMass());
    assert(!second_circle.ContainsSpeed());

    assert(false);
}

void ProcessCollisionFirstWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring)
{
    assert(circle.ContainsSpeed());
    assert(circle.ContainsMass());
    assert(!ring.ContainsSpeed());

    auto distance_vector = ring.GetCoordinates() - circle.GetCoordinates();
    circle.GetSpeed() -= 2.0 * CountProjection(object_coordinates(circle.GetSpeed()),  distance_vector);
}

void ProcessCollisionFirstWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle)
{
    //TODO: implement
    assert(ring.ContainsSpeed());
    assert(ring.ContainsMass());
    assert(!circle.ContainsSpeed());

    assert(false);
}

void ProcessCollisionFirstWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring)
{
    //TODO: implement
    assert(first_ring.ContainsSpeed());
    assert(first_ring.ContainsMass());
    assert(!second_ring.ContainsSpeed());

    assert(false);
}

void ProcessCollisionSecondWithSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle)
{
    ProcessCollisionFirstWithSpeed(second_circle, first_circle);
}

void ProcessCollisionSecondWithSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring)
{
    ProcessCollisionFirstWithSpeed(ring, circle);
}

void ProcessCollisionSecondWithSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle)
{
    ProcessCollisionFirstWithSpeed(circle, ring);
}

void ProcessCollisionSecondWithSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring)
{
    ProcessCollisionFirstWithSpeed(second_ring, first_ring);
}

void ProcessCollisionWithoutSpeed(ObjectInfo<const Circle>& first_circle, ObjectInfo<const Circle>& second_circle)
{
    //TODO: implement
    assert(!first_circle.ContainsSpeed());
    assert(!second_circle.ContainsSpeed());

    assert(false);
}

void ProcessCollisionWithoutSpeed(ObjectInfo<const Circle>& circle, ObjectInfo<const Ring>& ring)
{
    //TODO: implement
    assert(!circle.ContainsSpeed());
    assert(!ring.ContainsSpeed());

    assert(false);
}

void ProcessCollisionWithoutSpeed(ObjectInfo<const Ring>& ring, ObjectInfo<const Circle>& circle)
{
    ProcessCollisionWithoutSpeed(ring, circle);
}

void ProcessCollisionWithoutSpeed(ObjectInfo<const Ring>& first_ring, ObjectInfo<const Ring>& second_ring)
{
    //TODO: implement
    assert(!first_ring.ContainsSpeed());
    assert(!second_ring.ContainsSpeed());

    assert(false);
}