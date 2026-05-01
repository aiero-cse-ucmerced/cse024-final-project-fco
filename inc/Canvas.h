#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/canvas.h>
#include <Scribble.h>
#include <Point.h>
#include <vector>

class Canvas : public bobcat::Canvas_ {
std::vector<Scribble *> scribbles;
Scribble *currentScribble;
public:
    Canvas(int x, int y, int w, int h);
    void beginScribble();
    void addPoint(float x, float y, Color color);
    void endScribble();
    void clear();

    void render();

    ~Canvas();
};

#endif