#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <include/UsingAlias.hpp>
#include <include/VectorCoordinateOperations.hpp>

#include <vector>
#include <variant>

using coordinates = std::vector<coordinate_type>;

class Circle
{
  private:
    coordinates center_ = {0, 0};
    coordinate_type radius_ = 0;

  public:
    Circle() = default;
    Circle(coordinates center, coordinate_type radius);

    coordinates GetCenter() const;
    void SetCenter(coordinates coordinates);

};

void MoveObjectOnOffset(Circle& circle, offset_type offset);

using object = std::variant<Circle>;

#endif /* OBJECT_HPP */