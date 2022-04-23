#ifndef DRAW_OBJECT_HPP
#define DRAW_OBJECT_HPP

#include "UsingAliasMolecularBox.hpp"

#include "GraphicAdapter/UsingAliasGraphic.hpp"
#include "GraphicAdapter/GraphicInterface.hpp"
#include "Shape.hpp"

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const molecular_box_coordinate_system& coordinate_system, const object& object, 
                const object_coordinates& relative_coordinates)
{
    std::visit([graphic, &coordinate_system, &relative_coordinates](auto& object) {
        DrawObject(graphic, coordinate_system, object, relative_coordinates);
    }, object);
}

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const molecular_box_coordinate_system& coordinate_system, const Circle& circle, 
                const object_coordinates& relative_coordinates)
{
    auto screen_center_coordinates = coordinate_system.GetAbsoluteCoordinates(relative_coordinates);

    auto radius = circle.GetRadius();
    auto scaled_radius = coordinate_system.ScaleRelative(radius);

    graphic->DrawCircle(screen_center_coordinates, scaled_radius);
}

#endif /* DRAW_OBJECT_HPP */
