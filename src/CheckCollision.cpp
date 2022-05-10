#include <CheckCollision.hpp>

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_speed,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_speed)
{
    auto distance_vector = second_circle_center - first_circle_center;
    auto distance = CountLength(distance_vector);

    if (IsPenetrated(first_circle, second_circle, distance))
    {
        return true;
    }
    

    if (distance == first_circle.GetRadius() + second_circle.GetRadius())
    {
        if (IsCodirectional((CountProjection(first_circle_speed, distance_vector) - CountProjection(second_circle_speed, distance_vector)), distance_vector))
        {
            return true;
        }
    }


    return false;
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed)
{
    auto distance_vector = ring_coordinates - circle_coordinates;
    auto distance = CountLength(distance_vector);

    if (IsPenetrated(circle, ring, distance))
    {
        return true;
    }


    if (distance == ring.GetInnerRadius() - circle.GetRadius())
    {
        if (IsCodirectional((CountProjection(circle_speed, distance_vector) - CountProjection(ring_speed, distance_vector)), distance_vector))
        {
            return true;
        }


        return false;
    }


    if (distance == ring.GetOutterRadius() + circle.GetRadius())
    {
        if (IsCodirectional((CountProjection(ring_speed, distance_vector) - CountProjection(circle_speed, distance_vector)), distance_vector))
        {
            return true;
        }
    }


    return false;
}

bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed)

{
    return CheckCollision(circle, circle_coordinates, circle_speed,
                          ring,   ring_coordinates,   ring_speed);
}

bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,  const speed_type& first_ring_speed,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_speed)

{
    //TODO: Imlement

    UNUSED(first_ring)
    UNUSED(first_ring_center)
    UNUSED(first_ring_speed)
    UNUSED(second_ring)
    UNUSED(second_ring_center)
    UNUSED(second_ring_speed)

    assert(false);
    return false;
}

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_speed,
                    const Circle& second_circle, const object_coordinates& second_circle_center)
{
    //TODO: Optimize

    return CheckCollision(first_circle,  first_circle_center,  first_circle_speed,
                          second_circle, second_circle_center, speed_type({0, 0}));
}
bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates)

{
    //TODO: Optimize

    return CheckCollision(circle, circle_coordinates, circle_speed,
                          ring,   ring_coordinates,   speed_type({0, 0}));
}

bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates, const speed_type& ring_speed,
                    const Circle& circle, const object_coordinates& circle_coordinates)

{
    //TODO: Optimize

    return CheckCollision(ring,   ring_coordinates,   ring_speed,
                          circle, circle_coordinates, speed_type({0, 0}));
}

bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center, const speed_type& first_ring_speed,
                    const Ring& second_ring, const object_coordinates& second_ring_center)
{
    //TODO: Optimize

    return CheckCollision(first_ring,  first_ring_center,  first_ring_speed,
                          second_ring, second_ring_center, speed_type({0, 0}));
}

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_speed)
{
    return CheckCollision(second_circle, second_circle_center, second_circle_speed,
                          first_circle,  first_circle_center);
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                    const Ring& ring,     const object_coordinates& ring_coordinates, const speed_type& ring_speed)
{
    return CheckCollision(ring,   ring_coordinates, ring_speed,
                          circle, circle_coordinates);
}

bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                    const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed)
{
    return CheckCollision(circle, circle_coordinates, circle_speed,
                          ring,   ring_coordinates);
}

bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                    const Ring& second_ring, const object_coordinates& second_ring_center, const speed_type& second_ring_speed)
{
    return CheckCollision(second_ring, second_ring_center, second_ring_speed,
                          first_ring,  first_ring_center);
}

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,
                    const Circle& second_circle, const object_coordinates& second_circle_center)
{
    //TODO: optimize

    return CheckCollision(first_circle,  first_circle_center,  speed_type({0, 0}),
                          second_circle, second_circle_center, speed_type({0, 0}));
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates,
                    const Ring& ring,     const object_coordinates& ring_coordinates)
{
    //TODO: optimize

    return CheckCollision(circle, circle_coordinates, speed_type({0, 0}),
                          ring,   ring_coordinates,   speed_type({0, 0}));
}
            
bool CheckCollision(const Ring& ring,     const object_coordinates& ring_coordinates,
                    const Circle& circle, const object_coordinates& circle_coordinates)
{
    return CheckCollision(circle, circle_coordinates, ring, ring_coordinates);
}
                
bool CheckCollision(const Ring& first_ring,  const object_coordinates& first_ring_center,
                    const Ring& second_ring, const object_coordinates& second_ring_center)
{
    //TODO: optimize

    return CheckCollision(first_ring,  first_ring_center,  speed_type({0, 0}),
                          second_ring, second_ring_center, speed_type({0, 0}));
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