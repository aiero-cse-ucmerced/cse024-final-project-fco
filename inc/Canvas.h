// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CANVAS_H
#define CANVAS_H

#include "Point.h"
#include "Shape.h"
#include <bobcat_ui/canvas.h>

namespace aiero {

class Canvas : public bobcat::Canvas_ {
    std::vector<Point *> points;
    std::vector<Shape *> shapes;

    // TODO: history

    Shape *selectedShape;

public:
    Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
        selectedShape = nullptr;
    };

    bool checkMouseBounds(int x, int y) const { return true; };

    void deleteShape() {

    };

    void deleteObjectsFromMousePosition(float mx, float my);
};
}; // namespace aiero

#endif