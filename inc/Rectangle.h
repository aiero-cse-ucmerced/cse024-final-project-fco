#include <GL/gl.h>
#include "../inc/Color.h"
#include "../inc/shapers/Rectangle.h"
#include "../inc/shapers/rectangle.h"

Rectangle::Rectangle()
    : color(0, 0, 0)
{
    x = 0.0;
    y = 0.0;
    width  = 0.2;
    height = 0.2;
}


Rectangle::Rectangle(float _x, float _y, float _width, float _height, Color _color)
    : color(_color)
{
    x = _x;
    y = _y;
    width = _width;
    height = _height;
    color = _color;
}

void Rectangle::draw() const{
    glColor3f(color.r() / 255.0, color.g() / 255.0, color.b() / 255.0);

    glBegin(GL_POLYGON);
    glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}
