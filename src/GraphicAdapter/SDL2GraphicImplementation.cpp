#include <SDL2GraphicImplementation.hpp>

SDL2GraphicImplementation::SDL2GraphicImplementation(Init_type Init, GetResolution_type GetResolution, CreateWindow_type CreateWindow, SetColor_type SetColor, 
                                                     DrawCircle_type DrawCircle, DrawCircleWithColor_type DrawCircleWithColor,
                                                     DrawCircleRegion_type DrawCircleRegion, DrawCircleRegionWithColor_type DrawCircleRegionWithColor,
                                                     Refresh_type Refresh, Quit_type Quit) : 
                                                     Init_(Init), GetResolution_(GetResolution), CreateWindow_(CreateWindow), SetColor_(SetColor),
                                                     DrawCircle_(DrawCircle), DrawCircleWithColor_(DrawCircleWithColor),
                                                     DrawCircleRegion_(DrawCircleRegion), DrawCircleRegionWithColor_(DrawCircleRegionWithColor),
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

void SDL2GraphicImplementation::SetColor(color color) const
{
    SetColor_(renderer_, color);
}

void SDL2GraphicImplementation::DrawCircle(figure_coordinates center, figure_coordinate_type radius) const
{
    DrawCircle_(renderer_, center, radius);
}

void SDL2GraphicImplementation::DrawCircle(figure_coordinates center, figure_coordinate_type radius, color color) const
{
    DrawCircleWithColor_(renderer_, center, radius, color);
}

void SDL2GraphicImplementation::DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius) const
{
    DrawCircleRegion_(renderer_, center, radius);
}

void SDL2GraphicImplementation::DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius, color color) const
{
    DrawCircleRegionWithColor_(renderer_, center, radius, color);
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