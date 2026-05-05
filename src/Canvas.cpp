
/*
    FUNCTIONS:
        void clear();
        void sortLayers();
        void deleteCurrentLayer();
        void deleteLayer(int index);
        void deleteLayer(Shape* layerShape);
        void changeLayerPriority(Shape* layerShape, int priority);
        void bringLayerFront(Shape* layerShape);
        void bringLayerBack(Shape* layerShape);
        void bringLayerUp(Shape* layerShape);
        void bringLayerDown(Shape* layerShape);
        
        void addShape(Shape* shape);
        void deleteShape(Shape* shape);
        void deleteObjectsFromMousePosition(float mx, float my);

    EVENTS:
        virtual void onClickEvent(bobcat::Widget* sender) {};
        virtual void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
*/

#include "Canvas.h"
#include "Shape.h"
#include <vector>

using namespace std;
using namespace bobcat;
using namespace aiero;

void Canvas::addShape(Shape* shape) {
    layers.push_back({0, {shape}});
    redraw();
    std::cout << "shape added -> canvas redraw" << std::endl;
}

// POINTS TRACKER

void Canvas::startTrackingPoints() {
    if (_pointsTracked) return;
    _pointsTracked = true;
}

void Canvas::stopTrackingPoints() {
    if (!_pointsTracked) return;
    _pointsTracked = false;

    if (!ptsCollection.empty()) {
        // layers.push_back({0, utils::copyVector(ptsCollection)});
    }

    ptsCollection.clear();
}

void Canvas::render() {
    for (aiero::Layer l : layers) {
        for (Shape* s : l.shapes) {
            s->draw();
        }
    }
}