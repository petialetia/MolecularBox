#ifndef SDL2_GRAPHIC_IMPLEMENTATION_HPP
#define SDL2_GRAPHIC_IMPLEMENTATION_HPP

#include <SDL2/SDL.h>

#include "GraphicInterface.hpp"

#include <functional>

using Init_type =                      std::function<void()>;
using GetResolution_type =             std::function<display_size(SDL_DisplayMode&, display_number)>;
using CreateWindow_type =              std::function<void(SDL_Window*&, SDL_Renderer*&, std::string, window_coordinates, window_size)>;
using SetColor_type =                  std::function<void(SDL_Renderer* const&, color)>;
using DrawCircle_type =                std::function<void(SDL_Renderer* const&, figure_coordinates, figure_coordinate_type)>;
using DrawCircleWithColor_type =       std::function<void(SDL_Renderer* const&, figure_coordinates, figure_coordinate_type, color)>;
using DrawCircleRegion_type =          std::function<void(SDL_Renderer* const&, figure_coordinates, figure_coordinate_type)>;
using DrawCircleRegionWithColor_type = std::function<void(SDL_Renderer* const&, figure_coordinates, figure_coordinate_type, color)>;
using Refresh_type =                   std::function<void(SDL_Renderer* const&)>;
using Quit_type =                      std::function<void()>;

class SDL2GraphicImplementation : public GraphicInterface<SDL2GraphicImplementation>
{
  private:
    SDL_DisplayMode display_mode_ {};
    SDL_Window* window_ {};
    SDL_Renderer* renderer_ {};

    Init_type Init_;
    GetResolution_type GetResolution_;
    CreateWindow_type CreateWindow_;
    SetColor_type SetColor_;
    DrawCircle_type DrawCircle_;
    DrawCircleWithColor_type DrawCircleWithColor_;
    DrawCircleRegion_type DrawCircleRegion_;
    DrawCircleRegionWithColor_type DrawCircleRegionWithColor_;
    Refresh_type Refresh_;
    Quit_type Quit_;

  public:
    SDL2GraphicImplementation() = delete;

    SDL2GraphicImplementation(Init_type Init, GetResolution_type GetResolution, CreateWindow_type CreateWindow, SetColor_type SetColor, 
                              DrawCircle_type DrawCircle, DrawCircleWithColor_type DrawCircleWithColor,
                              DrawCircleRegion_type DrawCircleRegion, DrawCircleRegionWithColor_type DrawCircleRegionWithColor,
                              Refresh_type Refresh, Quit_type Quit);

    void Init();
    display_size GetResolution(display_number display);
    void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size);
    void SetColor(color color) const;
    void DrawCircle(figure_coordinates center, figure_coordinate_type radius) const;
    void DrawCircle(figure_coordinates center, figure_coordinate_type radius, color color) const;
    void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius) const;
    void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius, color color) const;
    void Refresh() const;
    void Quit();
    ~SDL2GraphicImplementation();
};

#endif /* SDL2_GRAPHIC_IMPLEMENTATION_HPP */
