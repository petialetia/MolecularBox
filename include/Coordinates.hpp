#ifndef COORDINATES_HPP
#define COORDINATES_HPP

#include <include/UsingAlias.hpp>
#include <include/VectorCoordinateOperations.hpp>

#include <vector>
#include <initializer_list>

class Coordinates: public std::vector<coordinate_type>
{
  public:
    explicit Coordinates() = default;
    explicit Coordinates(std::initializer_list<coordinate_type> list);
    explicit Coordinates(std::vector<coordinate_type> vector);

    Coordinates& operator+=(const Coordinates& other);
    Coordinates& operator*=(const coordinate_type other);
};

Coordinates operator+(Coordinates first, const Coordinates& second);
Coordinates operator*(Coordinates first, const coordinate_type second);

using coordinates = Coordinates;
using offset_type = Coordinates;

#endif /* COORDINATES_HPP */
