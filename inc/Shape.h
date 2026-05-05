// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "utils.h"

class Shape {
protected:
    float _x;
    float _y;

    float size;
    
    Color _color;
public:
    Shape() : _color(0, 0, 0) {
        _x = 0.0;
        _y = 0.0;
        size = 1;
    };

    Shape(float x, float y) : _x(x), _y(y), _color(0, 0, 0) {
        size = 1;
    };

    // TODO: copy constructor for history
    Shape(const Shape& parent) : _color(parent.color()) {

    };
    
    void color(Color newColor) {
        _color = newColor;
        // stuff happens
    };

    void changeSize(float s) { size = utils::clamp<float>(s, 0, 100); };
    
    const Color color() const { return _color; };
    virtual void draw() = 0;
    virtual bool checkMouseBounds(float mouseX, float mouseY) const = 0;

    virtual ~Shape() {
        // do nothing
    };
};

#endif