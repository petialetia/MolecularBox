#ifndef USING_ALIAS_GRAPHIC_HPP
#define USING_ALIAS_GRAPHIC_HPP

#include <vector>

using window_coordinates = std::vector<uint>;
using window_size = std::vector<uint>;

using figure_coordinate_type = uint;
using figure_coordinates = std::vector<figure_coordinate_type>;

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
