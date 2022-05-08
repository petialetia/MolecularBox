#include <SDL2GraphicImplementation.hpp>

SDL2GraphicImplementation::SDL2GraphicImplementation(Init_type Init, GetResolution_type GetResolution, 
                                                     CreateWindow_type CreateWindow, GetWindowSize_type GetWindowSize,
                                                     SetColor_type SetColor, ClearWindow_type ClearWindow, ClearWindowWithColor_type ClearWindowWithColor,
                                                     DrawCircumference_type DrawCircumference, DrawCircumferenceWithColor_type DrawCircleWithColor,
                                                     DrawCircle_type DrawCircle, DrawCircleWithColor_type DrawCircleRegionWithColor,
                                                     DrawRing_type DrawRing, DrawRingWithColor_type DrawRingWithColor,
                                                     Refresh_type Refresh, Quit_type Quit) : 
    Init_(Init), GetResolution_(GetResolution), CreateWindow_(CreateWindow), GetWindowSize_(GetWindowSize), SetColor_(SetColor),
    ClearWindow_(ClearWindow), ClearWindowWithColor_(ClearWindowWithColor), DrawCircle_(DrawCircumference), DrawCircleWithColor_(DrawCircleWithColor), 
    DrawCircleRegion_(DrawCircle), DrawCircleRegionWithColor_(DrawCircleRegionWithColor), DrawRing_(DrawRing), DrawRingWithColor_(DrawRingWithColor),
    Refresh_(Refresh), Quit_(Quit)
{
    Init();
}

void SDL2GraphicImplementation::Init()
{
    Init_();
}

display_size SDL2GraphicImplementation::GetResolution(display_number display)
{
    return GetResolution_(display_mode_, display);
}

void SDL2GraphicImplementation::CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size)
{
    CreateWindow_(window_, renderer_, name, win_coordinates, win_size);
}

window_size SDL2GraphicImplementation::GetWindowSize()
{
    return GetWindowSize_(window_);
}

void SDL2GraphicImplementation::SetColor(color color) const
{
    SetColor_(renderer_, color);
}

void SDL2GraphicImplementation::ClearWindow() const
{
    ClearWindow_(renderer_);
}

void SDL2GraphicImplementation::ClearWindow(color color) const
{
    ClearWindowWithColor_(renderer_, color);
}

void SDL2GraphicImplementation::DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius) const
{
    DrawCircle_(renderer_, center, radius);
}

void SDL2GraphicImplementation::DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius, color color) const
{
    DrawCircleWithColor_(renderer_, center, radius, color);
}

void SDL2GraphicImplementation::DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius) const
{
    DrawCircleRegion_(renderer_, center, radius);
}

void SDL2GraphicImplementation::DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius, color color) const
{
    DrawCircleRegionWithColor_(renderer_, center, radius, color);
}

void SDL2GraphicImplementation::DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius) const
{
    DrawRing_(renderer_, center, inner_radius, outter_radius);
}

void SDL2GraphicImplementation::DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius, 
                                         color color) const
{
    DrawRingWithColor_(renderer_, center, inner_radius, outter_radius, color);
}

void SDL2GraphicImplementation::Refresh() const
{
    Refresh_(renderer_);
}

void SDL2GraphicImplementation::Quit()
{
    Quit_();
}

SDL2GraphicImplementation::~SDL2GraphicImplementation()
{
    Quit();
}

SDL2GraphicImplementation GetSDL2GraphicImplementation()
{
   return SDL2GraphicImplementation(SDL2Graphic::Init, SDL2Graphic::GetResolution, SDL2Graphic::CreateWindow, SDL2Graphic::GetWindowSize,
                                    SDL2Graphic::SetColor, SDL2Graphic::ClearWindow, SDL2Graphic::ClearWindowWithColor,
                                    SDL2Graphic::DrawCircumference, SDL2Graphic::DrawCircumferenceWithColor, 
                                    SDL2Graphic::DrawCircle, SDL2Graphic::DrawCircleWithColor,
                                    SDL2Graphic::DrawRing, SDL2Graphic::DrawRingWithColor,
                                    SDL2Graphic::Refresh, SDL2Graphic::Quit);
}