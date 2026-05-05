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
#include <GL/gl.h>
#include <cmath>
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
    
}

void Diamond::draw() {
    
}

void Pentagon::draw() {
  glPointSize(size);
  
  const BaseColor color = _color.toBase();
  glColor3f(color.r,color.g,color.b);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 5; i++){
    double angle = (pi/2) + i * (2 * pi / 5.0);
    glVertex2f(_x + size*cos(angle), _y + size*sin(angle));
  }
  glEnd();   
}

void Rectangle::draw() {
    
}

void Star::draw() {
    
}

void Triangle::draw() {
  glPointSize(size);

  const BaseColor color = _color.toBase();
  glColor3f(color.r,color.g,color.b);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 3; i++){
    double angle = (pi/2) + i * (2 * pi / 3.0);
    glVertex2f(_x + size*cos(angle), _y + size*sin(angle));
  }
  glEnd();
}