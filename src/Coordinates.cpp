#include <include/Coordinates.hpp>

Coordinates::Coordinates(std::initializer_list<coordinate_type> list) : std::vector<coordinate_type>(list)
{
}

Coordinates::Coordinates(std::vector<coordinate_type> vector) : std::vector<coordinate_type>(vector)
{
}

Coordinates& Coordinates::operator+=(const Coordinates& other)
{
    TermByTermCompoundAddition(*this, other);
    return *this;
}

Coordinates& Coordinates::operator*=(const coordinate_type other)
{
    TermByTermCompoundMultiplication(*this, other);
    return *this;
}

Coordinates operator+(Coordinates first, const Coordinates& second)
{
    first+= second;
    return first;
}

Coordinates operator*(Coordinates first, const coordinate_type second)
{
    first*= second;
    return first;
}