#include <SDL2GraphicFunctions.hpp>

namespace SDL2Graphic
{

void Init()
{
    SDL_Init(SDL_INIT_VIDEO);
}

display_size GetResolution(SDL_DisplayMode& display_mode, display_number display)
{
    SDL_GetDesktopDisplayMode(display, &display_mode);
    return {static_cast<uint>(display_mode.w), static_cast<uint>(display_mode.h)};
}

void CreateWindow(SDL_Window*& window, SDL_Renderer*& renderer, std::string name, window_coordinates win_coordinates, window_size win_size)
{
    window = SDL_CreateWindow(name.c_str(), win_coordinates[0], win_coordinates[1], win_size[0], win_size[1], 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
}

void SetColor(SDL_Renderer* const& renderer, color color)
{
    SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, color.alpha);
}

void ClearWindow(SDL_Renderer* const& renderer)
{
    SDL_RenderClear(renderer);
}

void ClearWindowWithColor(SDL_Renderer* const& renderer, color color)
{
    SetColor(renderer, color);
    ClearWindow(renderer);
}

void DrawCircle(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius)
{
    auto x = radius;
    decltype(x) y = 0;

    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer, center[0] + y, center[1] - x);
        SDL_RenderDrawPoint(renderer, center[0] + x, center[1] - y);
        SDL_RenderDrawPoint(renderer, center[0] + x, center[1] + y);
        SDL_RenderDrawPoint(renderer, center[0] + y, center[1] + x);
        SDL_RenderDrawPoint(renderer, center[0] - y, center[1] + x);
        SDL_RenderDrawPoint(renderer, center[0] - x, center[1] + y);
        SDL_RenderDrawPoint(renderer, center[0] - x, center[1] - y);
        SDL_RenderDrawPoint(renderer, center[0] - y, center[1] - x);

        y += 1;
        double sin = static_cast<double>(y)/static_cast<double>(radius);
        double cos = std::sqrt(1 - sin*sin);
        x = cos / sin * static_cast<double>(y) + 0.5;
    }
}

void DrawCircleWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color)
{
    SetColor(renderer, color);
    DrawCircle(renderer, center, radius);
}

void DrawCircleRegion(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius)
{
    auto x = radius;
    decltype(x) y = 0;

    while (x >= y)
    {
        SDL_RenderDrawLine(renderer, center[0] + y, center[1] - x, center[0] - y, center[1] - x);
        SDL_RenderDrawLine(renderer, center[0] + x, center[1] - y, center[0] - x, center[1] - y);
        SDL_RenderDrawLine(renderer, center[0] + x, center[1] + y, center[0] - x, center[1] + y);
        SDL_RenderDrawLine(renderer, center[0] + y, center[1] + x, center[0] - y, center[1] + x);

        y += 1;
        double sin = static_cast<double>(y)/static_cast<double>(radius);
        double cos = std::sqrt(1 - sin*sin);
        x = cos / sin * static_cast<double>(y) + 0.5;
    }
}

void DrawCircleRegionWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color)
{
    SetColor(renderer, color);
    DrawCircleRegion(renderer, center, radius);
}

void Refresh(SDL_Renderer* const& renderer)
{
    SDL_RenderPresent(renderer);
}

void Quit()
{
    SDL_Quit();
}

} /* namespace SDL2Graphic */