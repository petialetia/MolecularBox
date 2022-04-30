#include <CheckCollision.hpp>

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_spped,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_spped)
{
    UNUSED(first_circle_spped)
    UNUSED(second_circle_spped)


    auto distance_vector = second_circle_center - first_circle_center;
    auto distance = CountLength(distance_vector);

    if (IsPenetrated(first_circle, second_circle, distance))
    {
        return true;
    }
    

    if (distance == first_circle.GetRadius() + second_circle.GetRadius())
    {
        //TODO: Implement
        assert(false);

        /*if IsCodirectional((CountProjection(first_circle_spped, distance_vector) - CountProjection(second_circle_spped, distance_vector)), distance_vector)
        {
            return true;
        }*/
    }


    return false;
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed)
{
    UNUSED(circle_speed)
    UNUSED(ring_speed)


    auto distance_vector = ring_coordinates - circle_coordinates;
    auto distance = CountLength(distance_vector);

    if (IsPenetrated(circle, ring, distance))
    {
        return true;
    }


    if (distance == ring.GetInnerRadius() - circle.GetRadius())
    {
        //TODO: Implement
        assert(false);
    }


    if (distance == ring.GetOutterRadius() + circle.GetRadius())
    {
        //TODO: Implement
        assert(false);
    }


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

bool IsPenetrated(const Circle& first_circle, const Circle& second_circle, const coordinate_type distance)
{
    return distance < first_circle.GetRadius() + second_circle.GetRadius();
}

bool IsPenetrated(const Circle& circle, const Ring& ring, const coordinate_type distance)
{
    return distance > ring.GetInnerRadius() - circle.GetRadius() && distance < ring.GetOutterRadius() + circle.GetRadius();
}

bool IsPenetrated(const Ring& ring, const Circle& circle, const coordinate_type distance)
{
    return IsPenetrated(circle, ring, distance);
}