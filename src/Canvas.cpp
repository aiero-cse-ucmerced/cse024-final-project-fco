#include <Canvas.h>
#include <GL/freeglut.h>

Canvas::Canvas(int x, int y, int w, int h) : bobcat::Canvas_(x, y, w, h) {
    //
    currentScribble = nullptr;
}

void Canvas::beginScribble() {
        currentScribble = new Scribble();
}

void Canvas::addPoint(float x, float y, Color color) {
    if(currentScribble != nullptr){
        currentScribble->addPoint(x, y, color);
        redraw();
    }
}

void Canvas::endScribble() {
    if (currentScribble != nullptr) {
        scribbles.push_back(currentScribble);
        currentScribble = nullptr;
    }
}

void Canvas::clear(){
    for (size_t i = 0; i < scribbles.size(); i++) {
        delete scribbles[i];
    }
    scribbles.clear();
     if (currentScribble != nullptr) {
        delete currentScribble;
        currentScribble = nullptr;
    }
}

void Canvas::render() {
for (size_t i = 0; i < scribbles.size(); i++) {
        scribbles[i]->draw();
    }
if (currentScribble != nullptr) {
        currentScribble->draw();
    }
}

Canvas::~Canvas() {
    clear();
}