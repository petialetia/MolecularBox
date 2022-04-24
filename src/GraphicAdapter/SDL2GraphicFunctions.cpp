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

window_size GetWindowSize(SDL_Window* const& window)
{
    assert(window != nullptr);

    int w = 0;
    int h = 0;

    SDL_GetWindowSize(window, &w, &h);

    assert(w >= 0 && h >= 0);

    window_size window_size {};
    window_size.push_back(w);
    window_size.push_back(h);

    return window_size;
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

void DrawCircumference(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius)
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
        double sin = static_cast<double>(y) / static_cast<double>(radius);
        double cos = std::sqrt(1 - sin * sin);
        x = round(cos / sin * static_cast<double>(y));
    }
}

void DrawCircleWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color)
{
    SetColor(renderer, color);
    DrawCircumference(renderer, center, radius);
}

void DrawCircle(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius)
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
        double sin = static_cast<double>(y) / static_cast<double>(radius);
        double cos = std::sqrt(1 - sin * sin);
        x = round(cos / sin * static_cast<double>(y));
    }
}

void DrawCircleRegionWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type radius, color color)
{
    SetColor(renderer, color);
    DrawCircle(renderer, center, radius);
}

void DrawRing(SDL_Renderer* const& renderer, coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius)
{
    auto inner_x = inner_radius;
    decltype(inner_x) inner_y = 0;

    auto outter_x = outter_radius;
    decltype(outter_x) outter_y = 0;

    while (inner_y <= inner_radius)
    {
        SDL_RenderDrawLine(renderer, center[0] - outter_x, center[1] - outter_y, center[0] - inner_x, center[1] - inner_y);
        SDL_RenderDrawLine(renderer, center[0] + inner_x, center[1] - inner_y, center[0] + outter_x, center[1] - outter_y);
        SDL_RenderDrawLine(renderer, center[0] - inner_x, center[1] + inner_y, center[0] - outter_x, center[1] + outter_y);
        SDL_RenderDrawLine(renderer, center[0] + inner_x, center[1] + inner_y, center[0] + outter_x, center[1] + outter_y);

        inner_y += 1;
        outter_y += 1;
        double outter_sin = static_cast<double>(outter_y) / static_cast<double>(outter_radius);
        double outter_cos = std::sqrt(1 - outter_sin * outter_sin);
        double inner_sin = static_cast<double>(inner_y) / static_cast<double>(inner_radius);
        double inner_cos = std::sqrt(1 - inner_sin * inner_sin);
        inner_x  = round(inner_cos  / inner_sin  * static_cast<double>(inner_y));
        outter_x = round(outter_cos / outter_sin * static_cast<double>(outter_y));
    }

    while (outter_y <= outter_radius)
    {
        SDL_RenderDrawLine(renderer, center[0] - outter_x, center[1] - outter_y, center[0] + outter_x, center[1] - outter_y);
        SDL_RenderDrawLine(renderer, center[0] - outter_x, center[1] + outter_y, center[0] + outter_x, center[1] + outter_y);

        outter_y += 1;
        double sin = static_cast<double>(outter_y) / static_cast<double>(outter_radius);
        double cos = std::sqrt(1 - sin * sin);
        outter_x = round(cos / sin * static_cast<double>(outter_y));
    } 
}

void DrawRingWithColor(SDL_Renderer* const& renderer, coordinates_on_screen center, 
                       coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius, color color)
{
    SetColor(renderer, color);
    DrawRing(renderer, center, inner_radius, outter_radius);
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