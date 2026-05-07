
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
        virtual _createHistory onClickEvent(bobcat::Widget* sender) {};
        virtual void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
*/

#include "Canvas.h"
#include "Point.h"
#include "Shape.h"
#include "utils.h"
#include <vector>
#include <algorithm>

using namespace std;
using namespace bobcat;
using namespace aiero;

void Canvas::addShape(Shape* shape) {
    layers.push_back({0, {shape}});
    _createHistory();
    // redraw();
    // std::cout << "shape added -> canvas redraw" << std::endl;
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
        layers.push_back({0, utils::copyVector<Shape*, Point*>(ptsCollection)});
        // layers.push_back({0, utils::copyVector(ptsCollection)});
    }

    ptsCollection.clear();
    
    _createHistory();
}

void Canvas::addPoint(Point* pt) {
    if (!_pointsTracked) return;
    ptsCollection.push_back(pt);
}

void Canvas::deletePoint(Point* pt) {
    if (ptsCollection.empty()) return;

    if (ptsCollection.back() == pt) {
        ptsCollection.pop_back();
        return;
    }
    
    auto it = std::find(ptsCollection.begin(), ptsCollection.end(), pt);
    if (it == ptsCollection.end()) return;
    
    int index = it - ptsCollection.begin();

    ptsCollection.erase(ptsCollection.begin() + index+1);
}

void Canvas::render() {
    // int count = 0;
    // int layerc = 0;
    
    for (aiero::Layer l : layers) {
        for (Shape* s : l.shapes) {
            s->draw();
            // count++;
            // std::cout << "drawn shape?";
        }
        
        // layerc++;
    }

    if (!ptsCollection.empty()) {
        for (Point* pt : ptsCollection) {
            pt->draw();
        }
    }

    // std::cout << "drawn shapes (" + std::to_string(count) + ")" << std::endl;
    // std::cout << "drawn layers (" + std::to_string(layerc) + ")" << std::endl;
    // cout << "canvas redrawn?" << endl;
}