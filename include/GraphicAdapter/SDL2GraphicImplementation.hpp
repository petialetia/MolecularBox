#ifndef SDL2_GRAPHIC_IMPLEMENTATION_HPP
#define SDL2_GRAPHIC_IMPLEMENTATION_HPP

#include <SDL2/SDL.h>

#include "GraphicInterface.hpp"
#include "SDL2GraphicFunctions.hpp"

#include <functional>

using Init_type =                       std::function<void()>;

using GetResolution_type =              std::function<display_size(SDL_DisplayMode&, display_number)>;
using CreateWindow_type =               std::function<void(SDL_Window*&, SDL_Renderer*&, std::string, window_coordinates, window_size)>;
using GetWindowSize_type =              std::function<window_size(SDL_Window* const&)>;

using SetColor_type =                   std::function<void(SDL_Renderer* const&, color)>;
using ClearWindow_type =                std::function<void(SDL_Renderer* const&)>;
using ClearWindowWithColor_type =       std::function<void(SDL_Renderer* const&, color)>;
using DrawCircumference_type =          std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type)>;
using DrawCircumferenceWithColor_type = std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type, color)>;
using DrawCircle_type =                 std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type)>;
using DrawCircleWithColor_type =        std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type, color)>;
using DrawRing_type =                   std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type, coordinate_on_screen_type)>;
using DrawRingWithColor_type =          std::function<void(SDL_Renderer* const&, coordinates_on_screen, coordinate_on_screen_type, coordinate_on_screen_type,
                                                           color)>; 
using Refresh_type =                    std::function<void(SDL_Renderer* const&)>;

using Quit_type =                       std::function<void()>;

class SDL2GraphicImplementation : public GraphicInterface<SDL2GraphicImplementation>
{
  private:
    SDL_DisplayMode display_mode_ {};
    SDL_Window* window_ {};
    SDL_Renderer* renderer_ {};

    Init_type Init_;
    GetResolution_type GetResolution_;
    CreateWindow_type CreateWindow_;
    GetWindowSize_type GetWindowSize_;
    SetColor_type SetColor_;
    ClearWindow_type ClearWindow_;
    ClearWindowWithColor_type ClearWindowWithColor_;
    DrawCircumference_type DrawCircle_;
    DrawCircumferenceWithColor_type DrawCircleWithColor_;
    DrawCircle_type DrawCircleRegion_;
    DrawCircleWithColor_type DrawCircleRegionWithColor_;
    DrawRing_type DrawRing_;
    DrawRingWithColor_type DrawRingWithColor_;
    Refresh_type Refresh_;
    Quit_type Quit_;

  public:
    SDL2GraphicImplementation() = delete;

    SDL2GraphicImplementation(Init_type Init, GetResolution_type GetResolution, CreateWindow_type CreateWindow, GetWindowSize_type GetWindowSize, 
                              SetColor_type SetColor, ClearWindow_type ClearWindow, ClearWindowWithColor_type ClearWindowWithColor,
                              DrawCircumference_type DrawCircumference, DrawCircumferenceWithColor_type DrawCircleWithColor,
                              DrawCircle_type DrawCircle, DrawCircleWithColor_type DrawCircleRegionWithColor,
                              DrawRing_type DrawRing, DrawRingWithColor_type DrawRingWithColor,
                              Refresh_type Refresh, Quit_type Quit);

    void Init();
    display_size GetResolution(display_number display);
    void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size);
    window_size GetWindowSize();
    void SetColor(color color) const;
    void ClearWindow() const;
    void ClearWindow(color color) const;
    void DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius) const;
    void DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius, color color) const;
    void DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius) const;
    void DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius, color color) const;
    void DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius) const;
    void DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius, color color) const;
    void Refresh() const;
    void Quit();
    ~SDL2GraphicImplementation();
};

SDL2GraphicImplementation GetSDL2GraphicImplementation();

#endif /* SDL2_GRAPHIC_IMPLEMENTATION_HPP */
