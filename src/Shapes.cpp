// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#include "Point.h"
#include "Tools.h"
#include "shapers/circle.h"
#include "shapers/diamond.h"
#include "shapers/pentagon.h"
#include "shapers/rectangle.h"
#include "shapers/star.h"
#include "shapers/triangle.h"

// Point has been created as an example
void Point::draw() {
    glPointSize(size);
        
    const BaseColor bColor = _color.toBase();
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    glBegin(GL_POINT);
        glVertex2f(_x, _y);
    glEnd();
}

// TODO: create the shape

void Circle::draw() {

    const BaseColor bColor = _color.toBase();
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    const int N = 32;
    const float TWO_PI = 6.2831;


    glBegin(GL_POLYGON);
    for(int i = 0; i < N; i ++){
        float angle = i * TWO_PI / N;
        float vx = x + radius * cos(angle);
        float vy = y + radius * sin(angle);

        glVertex2f(vx, vy);
    }
    glEnd();
}

void Diamond::draw() {
    
}

void Pentagon::draw() {
    
}

void Rectangle::draw() {
    glColor3f(color.r() / 255.0, color.g() / 255.0, color.b() / 255.0);
    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

void Star::draw() {
    
}

void Triangle::draw() {
    
}
