#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <UsingAliasMolecularBox.hpp>
#include <VectorCoordinateOperations.hpp>

#include <vector>
#include <variant>

class Circle
{
  private:
    coordinate_type radius_ = 0;

  public:
    explicit Circle() = default;
    explicit Circle(coordinate_type radius);
};

#endif /* SHAPE_HPP */
