// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"

class Shape {
protected:
    float _x;
    float _y;

    int size;
    
    Color _color;
public:
    Shape() : _color(0, 0, 0) {
        _x = 0.0;
        _y = 0.0;
    };
    
    virtual void color(Color newColor) {
        _color = newColor;
        // stuff happens
    };
    
    const Color color() const { return _color; };
    virtual void draw() = 0;
    virtual bool checkMouseBounds(float mouseX, float mouseY) const = 0;

    virtual ~Shape() {
        // do nothing
    };
};

#endif