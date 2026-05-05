// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Tool.h"
#include "../Enums.h"
#include "../Shape.h"
#include "../Color.h"
#include "../tools/CoreTool.h"

class Circle : public Shape {
public:
    Circle()
        : color(0, 0, 0)
    {
        x = 0.0;
        y = 0.0;
        radius = 25.0;
    }

    Circle(float _x, float _y, float _radius, Color _color)
        : color(_color)
    {
        x = _x;
        y = _y;
        radius = _radius;
    }

    void draw() override;

    bool checkMouseBounds(float mouseX, float mouseY) const override {

        return false;
    }

private:
    float x;
    float y;
    float radius;
    Color color;
};

class CircleTool : public aiero::CoreTool {
    TOOL _name = SHAPE_CIRCLE;

public:
    CircleTool() {}
    void onMouseDown(float x, float y) override;
    
    void _activate() override {}
    void _deactivate() override {}
};

#endif
