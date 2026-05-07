// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SHAPE_H
#define SHAPE_H

#include "Color.h"
#include "utils.h"
#include <iostream>

class Shape {
protected:
    float _x;
    float _y;

    float size;
    
    Color _color;
public:
    Shape() : _color(0, 0, 0) {
        // _x = 0.0;
        // _y = 0.0;
        size = 1;
    };

    Shape(float x, float y) : _x(x), _y(y), _color(0, 0, 0) {
        size = 1;
        // std::cout << "shape created at " << _x << ", " << _y << std::endl;
    };

    // TODO: copy constructor for history
    Shape(const Shape& parent) : _color(parent.color()) {
        _x = parent.x();
        _y = parent.y();
    };

    Shape(const Shape* parent) : Shape(*parent) {};

    // read only properties
    float x() const { return _x; };
    float y() const { return _y; };
    const Color color() const { return _color; };

    void color(Color newColor) {
        _color = newColor;
    };
    void color(int r, int g, int b) {
        _color = Color(r, g, b);
    };
    
    void changeSize(float s) { size = utils::clamp<float>(s, 0, 100); };
    
    virtual void draw() = 0;
    virtual bool checkMouseBounds(float mouseX, float mouseY) const = 0;
    virtual Shape* clone() = 0; // required for copying objects on Canvas

    virtual ~Shape() {
        // do nothing
    };
};

#endif