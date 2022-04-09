#include <include/SDL2GraphicAdapter.hpp>

SDL2GraphicAdapter::SDL2GraphicAdapter()
{
    SDL_Init(SDL_INIT_VIDEO);
}

display_size SDL2GraphicAdapter::GetResolution(display_number display)
{
    SDL_GetDesktopDisplayMode(display, &display_mode_);
    return {static_cast<uint>(display_mode_.w), static_cast<uint>(display_mode_.h)};
}

void SDL2GraphicAdapter::CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size)
{
    window_ = SDL_CreateWindow(name.c_str(), win_coordinates[0], win_coordinates[1], win_size[0], win_size[1], 0);
    renderer_ = SDL_CreateRenderer(window_, -1, 0);
}

void SDL2GraphicAdapter::SetColor(color color)
{
    SDL_SetRenderDrawColor(renderer_, color.red, color.green, color.blue, color.alpha);
}

void SDL2GraphicAdapter::DrawCircle(figure_coordinates center, figure_coordinate_type radius)
{
    auto x = radius;
    decltype(x) y = 0;

    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer_, center[0] + y, center[1] - x);
        SDL_RenderDrawPoint(renderer_, center[0] + x, center[1] - y);
        SDL_RenderDrawPoint(renderer_, center[0] + x, center[1] + y);
        SDL_RenderDrawPoint(renderer_, center[0] + y, center[1] + x);
        SDL_RenderDrawPoint(renderer_, center[0] - y, center[1] + x);
        SDL_RenderDrawPoint(renderer_, center[0] - x, center[1] + y);
        SDL_RenderDrawPoint(renderer_, center[0] - x, center[1] - y);
        SDL_RenderDrawPoint(renderer_, center[0] - y, center[1] - x);

        y += 1;
        double sin = static_cast<double>(y)/static_cast<double>(radius);
        double cos = std::sqrt(1 - sin*sin);
        x = cos / sin * static_cast<double>(y) + 0.5;
    }
}

void SDL2GraphicAdapter::DrawCircle(figure_coordinates center, figure_coordinate_type radius, color color)
{
    SetColor(color);
    DrawCircle(center, radius);
}

void SDL2GraphicAdapter::DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius)
{
    auto x = radius;
    decltype(x) y = 0;

    while (x >= y)
    {
        SDL_RenderDrawLine(renderer_, center[0] + y, center[1] - x, center[0] - y, center[1] - x);
        SDL_RenderDrawLine(renderer_, center[0] + x, center[1] - y, center[0] - x, center[1] - y);
        SDL_RenderDrawLine(renderer_, center[0] + x, center[1] + y, center[0] - x, center[1] + y);
        SDL_RenderDrawLine(renderer_, center[0] + y, center[1] + x, center[0] - y, center[1] + x);

        y += 1;
        double sin = static_cast<double>(y)/static_cast<double>(radius);
        double cos = std::sqrt(1 - sin*sin);
        x = cos / sin * static_cast<double>(y) + 0.5;
    }
}

void SDL2GraphicAdapter::DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius, color color)
{
    SetColor(color);
    DrawCircleRegion(center, radius);
}

void SDL2GraphicAdapter::Refresh()
{
    SDL_RenderPresent(renderer_);
}

SDL2GraphicAdapter::~SDL2GraphicAdapter()
{
    SDL_Quit();
}