#ifndef GRAPHIC_INTERFACE_HPP
#define GRAPHIC_INTERFACE_HPP

#include "UsingAliasGraphic.hpp"

#include <string>

template<typename Implementation>
class GraphicInterface
{
  protected:
    GraphicInterface() = default;

  private:
    void Init()
    {
        this->GetImplementation()->Init();
    }

  public:
    display_size GetResolution(display_number display)
    {
        return this->GetImplementation()->GetResolution(display);
    }

    void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size)
    {
        this->GetImplementation()->CreateWindow(name, win_coordinates, win_size);
    }

    window_size GetWindowSize()
    {
        return this->GetImplementation()->GetWindowSize();
    }

    void SetColor(color color)
    {
        this->GetImplementation()->SetColor(color);
    }

    void ClearWindow()
    {
        this->GetImplementation()->ClearWindow();
    }

    void ClearWindow(color color)
    {
        this->GetImplementation()->ClearWindow(color);
    }

    void DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius)
    {
        this->GetImplementation()->DrawCircumference(center, radius);
    }

    void DrawCircumference(coordinates_on_screen center, coordinate_on_screen_type radius, color color)
    {
        this->GetImplementation()->DrawCircumference(center, radius, color);
    }

    void DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius)
    {
        this->GetImplementation()->DrawCircle(center, radius);
    }

    void DrawCircle(coordinates_on_screen center, coordinate_on_screen_type radius, color color)
    {
        this->GetImplementation()->DrawCircle(center, radius, color);
    }

    void DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius)
    {
        this->GetImplementation()->DrawRing(center, inner_radius, outter_radius);
    }

    void DrawRing(coordinates_on_screen center, coordinate_on_screen_type inner_radius, coordinate_on_screen_type outter_radius, color color)
    {
        this->GetImplementation()->DrawRing(center, inner_radius, outter_radius, color);
    }

    void Refresh()
    {
        this->GetImplementation()->Refresh();
    }

  private:
    void Quit()
    {
        this->GetImplementation()->Quit();
    }

    Implementation* GetImplementation()
    {
        return static_cast<Implementation*>(this);
    }
};

#endif /* GRAPHIC_INTERFACE_HPP */
