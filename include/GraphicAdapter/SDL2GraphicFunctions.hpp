#ifndef SDL2_GRAPHIC_FUNCTIONS_HPP
#define SDL2_GRAPHIC_FUNCTIONS_HPP

#include "UsingAliasGraphic.hpp"

#include <SDL2/SDL.h>

#include <string>

namespace SDL2Graphic
{

void Init();

display_size GetResolution(SDL_DisplayMode& display_mode, display_number display);
void CreateWindow(SDL_Window*& window, SDL_Renderer*& renderer, 
                                      std::string name, window_coordinates win_coordinates, window_size win_size);
void SetColor(SDL_Renderer* const& renderer, color color);
void DrawCircle(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius);
void DrawCircleWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color);
void DrawCircleRegion(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius);
void DrawCircleRegionWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color);
void Refresh(SDL_Renderer* const& renderer);

void Quit();

} /* namespace SDL2Graphic */

#endif /* SDL2_GRAPHIC_FUNCTIONS_HPP */
