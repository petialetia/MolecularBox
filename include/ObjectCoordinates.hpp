#ifndef OBJECT_COORDINATES_HPP
#define OBJECT_COORDINATES_HPP

#include <include/UsingAlias.hpp>
#include <include/VectorCoordinateOperations.hpp>

#include <vector>
#include <initializer_list>

class ObjectCoordinates: public std::vector<coordinate_type>
{
  public:
    explicit ObjectCoordinates() = default;
    explicit ObjectCoordinates(std::initializer_list<coordinate_type> list);
    explicit ObjectCoordinates(std::vector<coordinate_type> vector);

    ObjectCoordinates& operator+=(const ObjectCoordinates& other);
    ObjectCoordinates& operator*=(const coordinate_type other);
};

ObjectCoordinates operator+(ObjectCoordinates first, const ObjectCoordinates& second);
ObjectCoordinates operator*(ObjectCoordinates first, const coordinate_type second);

using coordinates = ObjectCoordinates;
using offset_type = ObjectCoordinates;

#endif /* OBJECT_COORDINATES_HPP */
