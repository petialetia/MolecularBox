#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <include/UsingAlias.hpp>
#include <include/VectorCoordinateOperations.hpp>

#include <vector>
#include <variant>

class Circle
{
  private:
    coordinate_type radius_ = 0;

  public:
    Circle() = default;
    Circle(coordinate_type radius);
};

#endif /* SHAPE_HPP */
