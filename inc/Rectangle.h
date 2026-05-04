#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Color.h"
#include <GL/freeglut.h>

class Rectangle{
    float x;
    float y;
    float width;
    float height;
    Color color;

public:
    Rectangle();
    Rectangle(float _x, float _y, float _width, float _height, Color _color);
    void draw() const;
};


#endif
