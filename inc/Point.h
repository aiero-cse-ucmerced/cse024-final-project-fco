// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef POINT_H
#define POINT_H

#include "Color.h"
#include "Shape.h"

class Point : public Shape {

public:
    Point(int x, int y);
    
    virtual void color(Color newColor) override {
        _color = newColor;
        // stuff happens
    };
    
    Color color() const { return _color; };
    void draw() override;
    bool checkMouseBounds(float mouseX, float mouseY) const override {
        float dx = mouseX - _x;
        float dy = mouseY - _y;
        bool hit = dx*dx + dy*dy <= size*size;
        return hit;
    };
};

#endif