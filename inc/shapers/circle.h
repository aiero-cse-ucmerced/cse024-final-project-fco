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
        : Shape(0.0, 0.0), _radius(25.0)
    {
        _color = Color(0.0f, 0.0f, 0.0f); 
    }

   
    Circle(float Circx, float Circy, float radius, const Color& c)
        : Shape(Circx, Circy), _radius(radius)
    {
        _color = c; 
    }

    void draw() override;
    Shape* clone() const override {
        return new Circle(*this);
    };

    bool checkMouseBounds(float mouseX, float mouseY) const override {
        const float dx = mouseX - _x;
        const float dy = mouseY - _y;
        return (dx * dx + dy * dy) <= (_radius * _radius);
    }

   

private:
    float _radius;
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
