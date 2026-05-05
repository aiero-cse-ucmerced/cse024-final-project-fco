// Rectangle.h
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
        : Shape(0.0, 0.0), width(0.2), height(0.2)
    {
        // need f after for float literal
        _color = Color(0.0f, 0.0f, 0.0f);
    }

    
    Rectangle(float x, float y, float w, float h, const Color& c)
    :Shape(x, y), width(w), height(h)
    {
        _color = c;
    }

    void draw() override;
    bool checkMouseBounds(float mouseX, float mouseY) const override {
    return (mouseX >= _x - width * 0.5f && mouseX <= _x + width * 0.5f)
        && (mouseY >= _y - height * 0.5f && mouseY <= _y + height * 0.5f);
}


private:
    float width;
    float height;
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
