// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CANVAS_H
#define CANVAS_H

#include "Enums.h"
#include "History.h"
#include "Point.h"
#include "Shape.h"
#include "Toolbar.h"
#include "utils.h"

#include <GL/gl.h>
#include <bobcat_ui/canvas.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>
#include <vector>

namespace aiero {
struct Layer {
    int priority;
    std::vector<Shape *> shapes;
};

struct CanvasRecord {
    std::vector<Layer> layers;
};

struct CanvasGridSize {
    float width = 50;
    float height = 50;
};

class Canvas : public bobcat::Canvas_ {
    // std::vector<Point *> points;
    // std::vector<Shape *> shapes;
    CanvasGridSize gridSize;

    std::vector<Layer> layers;

    // TODO: history
    History<CanvasRecord> snapshots;

    Shape *selectedShape;

    void _applyHistory(CanvasRecord record) {
        bobcat::Canvas_::clear();
        layers.clear();

        for (Layer l : record.layers) {
            layers.push_back(l);
        }

        bobcat::Canvas_::redraw();
    };

    void _createHistory() {
        std::vector<Layer> savedLayers = utils::copyVector(layers);
        for (Layer l : savedLayers) {
            l.shapes = utils::deepCloneVector(l.shapes);
        }

        snapshots.add({savedLayers},
                      [this](CanvasRecord r) { _applyHistory(r); });
    };

    int _focusedLayerIndex;

    void _sortLayers() {

    };

    void _createLayer() {}

    // event handlers
    void _onMouseUpEventCb(bobcat::Widget *sender, float mouseX, float mouseY) {
        // std::cout << "internal mouse up event cb" << std::endl;
        onMouseUpEvent(sender, mouseX, mouseY);
    };
    void _onMouseDownEventCb(bobcat::Widget *sender, float mouseX,
                             float mouseY) {
        // std::cout << "internal mouse down event cb" << std::endl;
        onMouseDownEvent(sender, mouseX, mouseY);
    };
    void _onMouseDragEventCb(bobcat::Widget *sender, float mouseX,
                             float mouseY) {
        // std::cout << "internal mouse drag event cb" << std::endl;
        onMouseDragEvent(sender, mouseX, mouseY);
    };

    // points tracker
    bool _pointsTracked = false;
    std::vector<Point *> ptsCollection;

protected:
    virtual void onMouseUpEvent(bobcat::Widget *sender, float mouseX,
                                float mouseY) {};
    virtual void onMouseDownEvent(bobcat::Widget *sender, float mouseX,
                                  float mouseY) {};
    virtual void onMouseDragEvent(bobcat::Widget *sender, float mouseX,
                                  float mouseY) {};
    aiero::Toolbar *toolbar;

public:
    Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
        selectedShape = nullptr;
        toolbar = nullptr; // need to be initialized by the derived class
        _focusedLayerIndex = -1;

        snapshots = History<CanvasRecord>();
        _createHistory(); // create first history for blank slate

        gridSize = {10, 10};
    };

    void initEvents() {
        ON_MOUSE_UP(this, aiero::Canvas::_onMouseUpEventCb);
        ON_MOUSE_DOWN(this, aiero::Canvas::_onMouseDownEventCb);
        ON_DRAG(this, aiero::Canvas::_onMouseDragEventCb);
    };

    // layer system
    void changeLayerFocus(int index) {
        if ((int)layers.size() - 1 < index || index < 0)
            throw std::to_string(index) + " layer index does not exist";
        _focusedLayerIndex = index;
    };

    int focusedLayerIndex() const { return _focusedLayerIndex; };

    void clear();
    void sortLayers();
    void deleteCurrentLayer();
    void deleteLayer(int index);
    void deleteLayer(Shape *layerShape);
    void changeLayerPriority(Shape *layerShape, int priority);
    void bringLayerFront(Shape *layerShape);
    void bringLayerBack(Shape *layerShape);
    void bringLayerUp(Shape *layerShape);
    void bringLayerDown(Shape *layerShape);

    void addPoint(Point *pt);    // no history tracking
    void deletePoint(Point *pt); // no history tracking

    void startTrackingPoints();
    void stopTrackingPoints();

    void addShape(Shape *shape);
    void deleteShapesFromMousePosition(float mx, float my); // delete shapes
    void deleteLayersFromMousePosition(float mx, float my); // delete shapes

    struct LayeredShape {
        Layer layer;
        Shape *shape;
    };

    std::vector<LayeredShape> getShapesFromMousePosition(float mx, float my);
    std::vector<Layer> getLayersFromMousePosition(float mx, float my);

    void undoLayer() { snapshots.rewind(); };
    void redoLayer() { snapshots.forward(); };

    // required
    void render();
    // void render() {
    // const int x = 0;
    // const int y = 0;
    // const float width = 1 / gridSize.width;
    // const float height = 1 / gridSize.height;

    // glBegin(GL_POLYGON);
    //     glVertex2f(x,           y + height / 2.0f); // top
    //     glVertex2f(x + width / 2.0f, y);            // right
    //     glVertex2f(x,           y - height / 2.0f); // bottom
    //     glVertex2f(x - width / 2.0f, y);            // left
    // glEnd();
    // };
};
}; // namespace aiero

#endif