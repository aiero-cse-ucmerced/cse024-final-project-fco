#include <Canvas.h>
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    //
}


void Canvas::addPoint(float x, float y, Color color) {
    points.push_back(new Point(x, y, color));
}

void Canvas::render() {
 for (size_t i = 0; i < points.size(); i++) {
        points[i]->draw();
    }  
}