#include <include/Object.hpp>

Circle::Circle(coordinates center, coordinate_type radius) : center_(center), radius_(radius)
{
}

coordinates Circle::GetCenter() const
{
    return center_;
}

void Circle::SetCenter(coordinates center_coordinates)
{
    center_ = center_coordinates;
}

void Move(Circle& circle, offset_type offset)
{
    circle.SetCenter(TermByTermAddition(circle.GetCenter(), offset));
}