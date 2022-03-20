#include <vector>

#include "ForMolecularBox.hpp"

struct ObjectParams
{
  std::vector<coordinate_type> coordinates_ = {};
  coordinate_type radius_ = 0;
};

class Object 
{
  private:
    std::vector<coordinate_type> coordinates_ = {};
    coordinate_type radius = 0;

  public:
    explicit Object (std::vector<coordinate_type> coordinates, coordinate_type radius) : coordinates_(coordinates), radius(radius)
    {
    }
    explicit Object (ObjectParams params) : coordinates_(params.coordinates_), radius(params.radius_)
    {
    }
};