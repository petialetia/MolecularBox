#ifndef GRAPHIC_ADAPTER_HPP
#define GRAPHIC_ADAPTER_HPP

#include <vector>
#include <string>

using window_coordinates = std::vector<uint>;
using window_size = std::vector<uint>;

using figure_coordinates_type = uint;
using figure_coordinates = std::vector<figure_coordinates_type>;

struct color
{
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    unsigned char alpha = 0;
};

class GraphicAdapter
{
  public:
    virtual void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size) = 0;
    virtual void SetColor(color color) = 0;
    virtual void DrawCircle(figure_coordinates center, figure_coordinates_type radius) = 0;
    virtual void DrawCircle(figure_coordinates center, figure_coordinates_type radius, color color) = 0;
    virtual void DrawCircleRegion(figure_coordinates center, figure_coordinates_type radius) = 0;
    virtual void DrawCircleRegion(figure_coordinates center, figure_coordinates_type radius, color color) = 0;
    virtual void Refresh() = 0;
};

#endif /* GRAPHIC_ADAPTER_HPP */
