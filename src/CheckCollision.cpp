#include <CheckCollision.hpp>

#include <iostream>

bool CheckCollision(const Circle& first_circle,  const object_coordinates& first_circle_center,  const speed_type& first_circle_spped,
                    const Circle& second_circle, const object_coordinates& second_circle_center, const speed_type& second_circle_spped)
{
    std::cout << "Circle-circle collision" << std::endl;
    return true;
}

bool CheckCollision(const Circle& circle, const object_coordinates& circle_coordinates, const speed_type& circle_speed,
                    const Ring& ring,     const object_coordinates& ring_coordinates,   const speed_type& ring_speed)
{
    std::cout << "Circle-ring collision" << std::endl;
    return true;
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
    std::cout << "Ring-ring collsion" << std::endl;
    return true;
}