// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Tool.h"
#include "../Enums.h"
#include "../Shape.h"
#include "../Color.h"
#include "../tools/CoreTool.h"

class Rectangle : public Shape {
public:
    Rectangle()
        : color(0, 0, 0)
    {
        x = 0.0f;
        y = 0.0f;
        width  = 0.2f;
        height = 0.2f;
    }

    Rectangle(float _x, float _y, float _width, float _height, Color _color)
        : color(_color)
    {
        x = _x;
        y = _y;
        width  = _width;
        height = _height;
    }

    void draw() override;

    bool checkMouseBounds(float mouseX, float mouseY) const override {
        return false;
    }

private:
    float x;
    float y;
    float width;
    float height;
    Color color;
};

class RectangleTool : public aiero::CoreTool {
    TOOL _name = SHAPE_RECTANGLE;

public:
    RectangleTool() {}

    void onMouseDown(float x, float y) override;

    void _activate() override {}
    void _deactivate() override {}
};

#endif
