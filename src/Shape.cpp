#include <Shape.hpp>

Circle::Circle(coordinate_type radius) : 
    radius_(radius)
{
}

coordinate_type Circle::GetRadius() const
{
    return radius_;
}

Ring::Ring(coordinate_type inner_radius, coordinate_type width) :
    inner_radius_(inner_radius), width_(width)
{
}