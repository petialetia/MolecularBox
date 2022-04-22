#include <Shape.hpp>

Circle::Circle(coordinate_type radius) : 
    radius_(radius)
{
}

coordinate_type Circle::GetRadius() const
{
    return radius_;
}