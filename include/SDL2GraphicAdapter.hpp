#ifndef SDL2_GRAPHIC_ADAPTER_HPP
#define SDL2_GRAPHIC_ADAPTER_HPP

#include <include/GraphicAdapter.hpp>
#include <SDL2/SDL.h>

#include <cmath>

class SDL2GraphicAdapter : public GraphicAdapter
{
  private:
    SDL_Window* window_ {};
    SDL_Renderer* renderer_ {};

  public:
    SDL2GraphicAdapter() = default;

    virtual void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size) override;
    virtual void SetColor(color color) override;
    virtual void DrawCircle(figure_coordinates center, figure_coordinate_type radius) override;
    virtual void DrawCircle(figure_coordinates center, figure_coordinate_type radius, color color) override;
    virtual void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius) override;
    virtual void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius, color color) override;
    virtual void Refresh() override;
};

#endif /* SDL2_GRAPHIC_ADAPTER_HPP */
