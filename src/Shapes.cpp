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

    const BaseColor bColor = _color.toBase();
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    const int NUM_SEGMENTS = 32;
    const float TWO_PI = 6.2831;


    glBegin(GL_POLYGON);
    for(int i = 0; i < NUM_SEGMENTS; i ++){
        float angle = i * TWO_PI / NUM_SEGMENTS;
        float vx = _x + _radius * cos(angle);
        float vy = _y + _radius * sin(angle);

        glVertex2f(vx, vy);
    }
    glEnd();
}

void Diamond::draw() {
    const BaseColor b = _color.toBase();
    glColor3f(b.r, b.g, b.b);

    glBegin(GL_POLYGON);
        glVertex2f(_x, _y + (height * 0.5f)); 
        glVertex2f(_x + (width * 0.5f), _y);               
        glVertex2f(_x,_y - (height * 0.5f)); 
        glVertex2f(_x - (width * 0.5f), _y);               
    glEnd();
    
}

void Pentagon::draw() {
  glPointSize(size);
  
  const BaseColor color = _color.toBase();
  glColor3f(color.r,color.g,color.b);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 5; i++){
    double angle = (pi/2) + i * (2 * pi / 5.0);
    glVertex2f(_x + size*std::cos(angle), _y + size*std::sin(angle));
  }
  glEnd();   
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
    const BaseColor bColor = _color.toBase();
    
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    const int VERTICES = 10;
    const float PI = 3.141592;
    const float TWO_PI = 2 * PI;

    const float startAngle = PI * 0.5;

    //Fill star
    glBegin(GL_POLYGON);
    for(int i = 0; i < VERTICES; i ++){
        float r;
        if(i % 2 ==0){
            r = outerRadius;
        } else {
            r = innerRadius;
        }
        //converted deg to rad
        float angle = startAngle + i * (TWO_PI / float(VERTICES)); 
        float vx = _x + r * cos(angle);
        float vy = _y + r * sin(angle);
        glVertex2f(vx, vy);  
    }
    glEnd();

    // outline
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < VERTICES; ++i) {
         float r;
        if(i % 2 ==0){
            r = outerRadius;
        } else {
            r = innerRadius;
        }
        //converted deg to rad
        float angle = startAngle + i * (TWO_PI / float(VERTICES)); 
        float vx = _x + r * cos(angle);
        float vy = _y + r * sin(angle);
        glVertex2f(vx, vy);
    }
    glEnd();
}

void Triangle::draw() {
  glPointSize(size);

  const BaseColor color = _color.toBase();
  glColor3f(color.r,color.g,color.b);
  glBegin(GL_POLYGON);
  for(int i = 0; i < 3; i++){
    double angle = (pi/2) + i * (2 * pi / 3.0);
    glVertex2f(_x + size*std::cos(angle), _y + size*std::sin(angle));
  }
  glEnd();
}
