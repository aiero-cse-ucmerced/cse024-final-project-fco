// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"

class Shape {
protected:
    float _x;
    float _y;
    
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
    
    Color color() const { return _color; };
    virtual void draw() = 0;
    virtual bool checkMouseBounds() const = 0;

    virtual ~Shape() {
        // do nothing
    };
};

#endif