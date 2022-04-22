#ifndef DRAW_OBJECT_HPP
#define DRAW_OBJECT_HPP

#include "GraphicAdapter/UsingAliasGraphic.hpp"
#include "GraphicAdapter/GraphicInterface.hpp"
#include "Shape.hpp"

#include <iostream>

template <typename Implementation>
void DrawObject(GraphicInterface<Implementation>* const graphic, const Circle circle, const coordinates_on_screen center_coordinates)
{
    graphic->DrawCircle(center_coordinates, circle.GetRadius());
}

#endif /* DRAW_OBJECT_HPP */
