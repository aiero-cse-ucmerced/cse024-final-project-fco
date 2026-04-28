#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/canvas.h>
#include <Point.h>
#include <vector>

class Canvas : public bobcat::Canvas_ {
std::vector<Point *> points;
public:
    Canvas(int x, int y, int w, int h);
    void addPoint(float x, float y, Color color);

    void render();
};

#endif