#ifndef COORDINATE_SYSTEM_HPP
#define COORDINATE_SYSTEM_HPP

#include "Coordinates.hpp"

template<typename absolute_t, typename relative_t>
class CoordinateSystem
{
  private:
    const Coordinates<absolute_t> origin_ {0, 0};
    const Coordinates<absolute_t> single_segment_length_ {1, 1};

  public:
    explicit CoordinateSystem(Coordinates<absolute_t> origin, Coordinates<absolute_t> single_segment_length) :
        origin_(origin), single_segment_length_(single_segment_length)
    {
        assert(origin_.size() == single_segment_length_.size());
    }

    Coordinates<relative_t> GetRelativeCoordinates(Coordinates<absolute_t> absolute) const
    {
        return relative_coordinates(absolute - origin_) / relative_coordinates(single_segment_length_);  
    }

    Coordinates<absolute_t> GetAbsoluteCoordinates(Coordinates<relative_t> relative) const
    {
        return Coordinates<absolute_t>(relative) * single_segment_length_ + origin_;
    }
};

#endif /* COORDINATE_SYSTEM_HPP */
