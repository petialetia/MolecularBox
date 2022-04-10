#ifndef GRAPHIC_INTERFACE_HPP
#define GRAPHIC_INTERFACE_HPP

#include <include/UsingAliasGraphic.hpp>

#include <string>

template<typename Implementation>
class GraphicInterface
{
  public:
    GraphicInterface() = default;

    void Init()
    {
        GetImplemetation()->Init();
    }

    display_size GetResolution(display_number display)
    {
        return this->GetImplementation()->GetResolution(display);
    }

    void CreateWindow(std::string name, window_coordinates win_coordinates, window_size win_size)
    {
        this->GetImplementation()->CreateWindow(name, win_coordinates, win_size);
    }

    void SetColor(color color)
    {
        this->GetImplementation()->SetColor(color);
    }

    void DrawCircle(figure_coordinates center, figure_coordinate_type radius)
    {
        this->GetImplementation()->DrawCircle(center, radius);
    }

    void DrawCircle(figure_coordinates center, figure_coordinate_type radius, color color)
    {
        this->GetImplementation()->DrawCircle(center, radius, color);
    }

    void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius)
    {
        this->GetImplemetation()->DrawCircleRegion(center, radius);
    }

    void DrawCircleRegion(figure_coordinates center, figure_coordinate_type radius, color color)
    {
        this->GetImplemetation()->DrawCircleRegion(center, radius, color);
    }

    void Refresh()
    {
        this->GetImplemetation()->Refresh();
    }

    void Quit()
    {
        this->GetImplemetation()->Refresh();
    }

  private:
    Implementation* GetImplemetation()
    {
        return static_cast<Implementation*>(this);
    }
};

#endif /* GRAPHIC_INTERFACE_HPP */
