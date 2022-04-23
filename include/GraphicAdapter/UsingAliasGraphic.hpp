#ifndef USING_ALIAS_GRAPHIC_HPP
#define USING_ALIAS_GRAPHIC_HPP

#include <Coordinates.hpp>

#include <vector>

using uint = unsigned int;

using window_coordinates = Coordinates<uint>;
using window_size = std::vector<uint>;

using coordinate_on_screen_type = int;
using coordinates_on_screen = Coordinates<coordinate_on_screen_type>;

using display_number = uint;
using display_size = std::vector<uint>;

struct color
{
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    unsigned char alpha = 0;
};

#endif /* USING_ALIAS_GRAPHIC_HPP */
