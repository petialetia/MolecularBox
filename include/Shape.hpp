#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "UsingAliasMolecularBox.hpp"
#include "VectorCoordinateOperations.hpp"

#include <vector>
#include <variant>

class Circle
{
  private:
    coordinate_type radius_ = 0;

  public:
    explicit Circle() = default;
    explicit Circle(coordinate_type radius);

    coordinate_type GetRadius() const;
};

class Ring
{
  private:
    coordinate_type inner_radius_ = 0;
    coordinate_type width_ = 0;

  public:
    explicit Ring() = default;
    explicit Ring(coordinate_type inner_radius, coordinate_type width);

    coordinate_type GetInnerRadius() const;
    coordinate_type GetOutterRadius() const;
    coordinate_type GetWidth() const;
};

#endif /* SHAPE_HPP */
