// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef POINT_H
#define POINT_H

#include "Color.h"

class Point {
protected:
    float _x, _y;
    int size;
    
    Color _color;
public:
    Point(int x, int y);
    
    virtual void color(Color newColor) {
        _color = newColor;
        // stuff happens
    };
    
    Color color() const { return _color; };
    virtual void draw();
    virtual bool checkMouseBounds(int mouseX, int mouseY) {
        float dx = mouseX - _x;
        float dy = mouseY - _y;
        bool hit = dx*dx + dy*dy <= size*size;
        return hit;
    };
};

#endif