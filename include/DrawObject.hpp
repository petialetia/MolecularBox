#ifndef DRAW_OBJECT_HPP
#define DRAW_OBJECT_HPP

#include "UsingAliasMolecularBox.hpp"

#include "GraphicAdapter/UsingAliasGraphic.hpp"
#include "GraphicAdapter/GraphicInterface.hpp"
#include "Shape.hpp"

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const molecular_box_coordinate_system& coordinate_system, const object& object, 
                const object_coordinates& relative_coordinates, const color color)
{
    std::visit([graphic, &coordinate_system, &relative_coordinates, color](auto& object) {
        DrawObject(graphic, coordinate_system, object, relative_coordinates, color);
    }, object);
}

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const molecular_box_coordinate_system& coordinate_system, const Circle& circle, 
                const object_coordinates& relative_coordinates, const color color)
{
    auto screen_center_coordinates = coordinate_system.GetAbsoluteCoordinates(relative_coordinates);

    auto radius = circle.GetRadius();
    auto scaled_radius = coordinate_system.ScaleRelative(radius);

    graphic->DrawCircle(screen_center_coordinates, scaled_radius, color);
}

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const molecular_box_coordinate_system& coordinate_system, const Ring& ring, 
                const object_coordinates& relative_coordinates, const color color)
{
    auto screen_center_coordinates = coordinate_system.GetAbsoluteCoordinates(relative_coordinates);
    auto inner_radius = ring.GetInnerRadius();
    auto outter_radius = ring.GetOutterRadius();

    auto scaled_inner_radius = coordinate_system.ScaleRelative(inner_radius);
    auto scaler_outter_radius = coordinate_system.ScaleRelative(outter_radius);

    graphic->DrawRing(screen_center_coordinates, scaled_inner_radius, scaler_outter_radius, color);
}

#endif /* DRAW_OBJECT_HPP */
