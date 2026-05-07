// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef POINT_H
#define POINT_H

#include "Color.h"
#include "Shape.h"
#include <GL/gl.h>

class Point : public Shape {

public:
    Point(float x, float y) {
        _x = x;
        _y = y;
    };

    Point(const Point& parentPt) : Shape(parentPt) {
        // do nothing
    };
    
    Point(const Point* parentPt) : Point(*parentPt) {}; // calls the first copy constructor for pointers

    void draw() override;
    Shape* clone() override {
        return new Point(*this);
    };
    
    bool checkMouseBounds(float mouseX, float mouseY) const override {
        float dx = mouseX - _x;
        float dy = mouseY - _y;
        bool hit = dx*dx + dy*dy <= size*size;
        return hit;
    };
};

#endif