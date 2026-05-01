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

    virtual void onClickEvent(bobcat::Widget* sender) {};
    virtual void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
    virtual void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
    virtual void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
public:
    Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
        selectedShape = nullptr;
        this->end();
    };

    void clear();

    bool checkMouseBounds(int x, int y) const { return true; };

    void deleteShape() {

    };

    void deleteObjectsFromMousePosition(float mx, float my);
    
    // required
    void render() {

    };
};
}; // namespace aiero

#endif