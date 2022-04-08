#include <include/ObjectCoordinates.hpp>

ObjectCoordinates::ObjectCoordinates(std::initializer_list<coordinate_type> list) : std::vector<coordinate_type>(list)
{
}

ObjectCoordinates::ObjectCoordinates(std::vector<coordinate_type> vector) : std::vector<coordinate_type>(vector)
{
}

ObjectCoordinates& ObjectCoordinates::operator+=(const ObjectCoordinates& other)
{
    TermByTermCompoundAddition(*this, other);
    return *this;
}

ObjectCoordinates& ObjectCoordinates::operator*=(const coordinate_type other)
{
    TermByTermCompoundMultiplication(*this, other);
    return *this;
}

ObjectCoordinates operator+(ObjectCoordinates first, const ObjectCoordinates& second)
{
    first+= second;
    return first;
}

ObjectCoordinates operator*(ObjectCoordinates first, const coordinate_type second)
{
    first*= second;
    return first;
}