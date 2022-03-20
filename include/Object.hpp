#include <vector>

#include "UsingAlias.hpp"

using coordinates = std::vector<coordinate_type>;

enum shape_type
{
  circle
};

class Shape
{
  private:
    const shape_type type_;

  protected:

    Shape(shape_type type) : type_(type)
    {
    }

  public:

    shape_type GetType()
    {
        return type_;
    }
};

class Circle: public Shape
{
  private:
    coordinates center_ = {0, 0};
    coordinate_type radius_ = 0;

  public:
    Circle(coordinates center, coordinate_type radius) : center_(center), radius_(radius), Shape(circle)
    {
    }
};

using Object = Shape;