#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include <bobcat_ui/all.h>

#include <Point.h>
#include <Color.h>
#include <GL/freeglut.h>
#include <vector>

class Scribble{
   std::vector<Point *> points;
   float x;
   float y;
   int size;
   Color color;

public:
    Scribble(float x, float y, Color color);
    void draw() const;
    ~Scribble();
};