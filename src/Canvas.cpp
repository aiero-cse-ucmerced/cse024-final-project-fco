#include <Canvas.h>
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    //
}


void Canvas::addScribble(float x, float y, Color color) {
    scribbles.push_back(new Scribble(x, y, color));
}


void Canvas::render() {
for (size_t i = 0; i < scribbles.size(); i++) {
        scribbles[i]->draw();
    }
}

Canvas::~Canvas(){
    clear();
}