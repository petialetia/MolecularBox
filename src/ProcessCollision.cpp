#include <ProcessCollision.hpp>

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  speed_type& first_circle_speed,
                      const Circle& second_circle, const object_coordinates& second_circle_center, speed_type& second_circle_speed)
{
    UNUSED(first_circle)
    UNUSED(second_circle)

    auto distance_vector = second_circle_center - first_circle_center;
    first_circle_speed  -= 2.0 * CountProjection(object_coordinates(first_circle_speed),  distance_vector);
    second_circle_speed -= 2.0 * CountProjection(object_coordinates(second_circle_speed), distance_vector);
}

void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed,
                      const Ring& ring,     const object_coordinates& ring_coordinates,   speed_type& ring_speed)
{
    UNUSED(circle)
    UNUSED(circle_speed)
    UNUSED(ring_speed)

    auto distance_vector = ring_coordinates - circle_coordinates;
    auto distance = CountLength(distance_vector);

    if (distance >= ring.GetInnerRadius() + ring.GetWidth() / 2)
    {
        //TODO: implement outter collision
        assert(false);
    }


    //TODO: implement inner collision
    assert(false);
}

void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   speed_type& ring_speed,
                      const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed)
{
    ProcessCollision(circle, circle_coordinates, circle_speed,
                     ring,   ring_coordinates,   ring_speed);
}

void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  speed_type& first_ring_speed,
                      const Ring& second_ring, const object_coordinates& second_ring_center, speed_type& second_ring_speed)
{
    //TODO: implement

    UNUSED(first_ring)
    UNUSED(first_ring_center)
    UNUSED(first_ring_speed)
    UNUSED(second_ring)
    UNUSED(second_ring_center)
    UNUSED(second_ring_speed)

    assert(false);
}

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  speed_type& first_circle_speed,
                      const Circle& second_circle, const object_coordinates& second_circle_center)
{
    //TODO: implement

    UNUSED(first_circle)
    UNUSED(first_circle_center)
    UNUSED(first_circle_speed)
    UNUSED(second_circle)
    UNUSED(second_circle_center)

    assert(false);
}

void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed,
                      const Ring& ring,     const object_coordinates& ring_coordinates)
{
    UNUSED(circle)

    auto distance_vector = ring_coordinates - circle_coordinates;
    auto distance = CountLength(distance_vector);

    if (distance >= ring.GetInnerRadius() + ring.GetWidth() / 2)
    {
        //TODO: implement outter collision
        assert(false);
    }

    circle_speed -= 2.0 * CountProjection(object_coordinates(circle_speed),  distance_vector);
}

void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   speed_type& ring_speed,
                      const Circle& circle, const object_coordinates& circle_coordinates)
{
    //TODO: implement

    UNUSED(ring)
    UNUSED(ring_coordinates)
    UNUSED(ring_speed)
    UNUSED(circle)
    UNUSED(circle_coordinates)

    assert(false);
}

void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  speed_type& first_ring_speed,
                      const Ring& second_ring, const object_coordinates& second_ring_center)
{
    //TODO: implement

    UNUSED(first_ring)
    UNUSED(first_ring_center)
    UNUSED(first_ring_speed)
    UNUSED(second_ring)
    UNUSED(second_ring_center)

    assert(false);
}

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                      const Circle& second_circle, const object_coordinates& second_circle_center, speed_type& second_circle_speed)
{
    ProcessCollision(second_circle, second_circle_center, second_circle_speed,
                     first_circle,  first_circle_center);
}

void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                      const Ring& ring,     const object_coordinates& ring_coordinates, speed_type& ring_speed)
{
    ProcessCollision(ring,   ring_coordinates, ring_speed,
                     circle, circle_coordinates);
}

void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                      const Circle& circle, const object_coordinates& circle_coordinates, speed_type& circle_speed)
{
    ProcessCollision(circle, circle_coordinates, circle_speed,
                     ring,   ring_coordinates);
}

void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                      const Ring& second_ring, const object_coordinates& second_ring_center, speed_type& second_ring_speed)
{
    ProcessCollision(second_ring, second_ring_center, second_ring_speed,
                     first_ring,  first_ring_center);
}

void ProcessCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                      const Circle& second_circle, const object_coordinates& second_circle_center)
{
    //TODO: implement

    UNUSED(first_circle)
    UNUSED(first_circle_center)
    UNUSED(second_circle)
    UNUSED(second_circle_center)

    assert(false);
}

void ProcessCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                      const Ring& ring,     const object_coordinates& ring_coordinates)
{
    //TODO: implement

    UNUSED(circle)
    UNUSED(circle_coordinates)
    UNUSED(ring)
    UNUSED(ring_coordinates)

    assert(false);
}

void ProcessCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                      const Circle& circle, const object_coordinates& circle_coordinates)
{
    ProcessCollision(circle, circle_coordinates,
                     ring,   ring_coordinates);
}

void ProcessCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                      const Ring& second_ring, const object_coordinates& second_ring_center)
{
    //TODO: implement

    UNUSED(first_ring)
    UNUSED(first_ring_center)
    UNUSED(second_ring)
    UNUSED(second_ring_center)

    assert(false);
}