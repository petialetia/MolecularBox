#ifndef COORDINATE_SYSTEM_HPP
#define COORDINATE_SYSTEM_HPP

#include "Coordinates.hpp"

template<typename absolute_t, typename relative_t>
class CoordinateSystem
{
  public:
    using absolute_coordinates = Coordinates<absolute_t>;
    using relative_coordinates = Coordinates<relative_t>;

  private:
    const absolute_coordinates origin_ {0, 0};
    const absolute_coordinates single_segment_length_ {1, 1};

  public:
    explicit CoordinateSystem(absolute_coordinates origin, absolute_coordinates single_segment_length) :
        origin_(origin), single_segment_length_(single_segment_length)
    {
        assert(origin_.size() == single_segment_length_.size());
    }

    relative_coordinates GetRelativeCoordinates(absolute_coordinates absolute) const
    {
        return relative_coordinates(absolute - origin_) / relative_coordinates(single_segment_length_);  
    }

    absolute_coordinates GetAbsoluteCoordinates(relative_coordinates relative) const
    {
        return absolute_coordinates(relative) * single_segment_length_ + origin_;
    }
};

#endif /* COORDINATE_SYSTEM_HPP */
