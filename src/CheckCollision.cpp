#include <CheckCollision.hpp>

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_spped,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_spped)
{
    //TODO: Imlement

    UNUSED(first_circle)
    UNUSED(first_circle_center)
    UNUSED(first_circle_spped)
    UNUSED(second_circle)
    UNUSED(second_circle_center)
    UNUSED(second_circle_spped)

    assert(false);
    return false;
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed)
{
    //TODO: Imlement

    UNUSED(circle)
    UNUSED(circle_coordinates)
    UNUSED(circle_speed)
    UNUSED(ring)
    UNUSED(ring_coordinates)
    UNUSED(ring_speed)

    assert(false);
    return false;
}

bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed)

{
    return CheckCollision(circle, circle_coordinates, circle_speed,
                          ring,   ring_coordinates,   ring_speed);
}

bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  const speed_type& first_ring_spped,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_spped)

{
    //TODO: Imlement

    UNUSED(first_ring)
    UNUSED(first_ring_center)
    UNUSED(first_ring_spped)
    UNUSED(second_ring)
    UNUSED(second_ring_center)
    UNUSED(second_ring_spped)

    assert(false);
    return false;
}