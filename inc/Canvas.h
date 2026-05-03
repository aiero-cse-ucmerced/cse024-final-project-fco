// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CANVAS_H
#define CANVAS_H

#include "Enums.h"
#include "Point.h"
#include "Shape.h"
#include "History.h"
#include "Toolbar.h"

#include <GL/gl.h>
#include <bobcat_ui/canvas.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>

namespace aiero {
    struct Layer {
        int priority;
        Shape* shape;
    };

    struct CanvasRecord {
        
    };

    class Canvas : public bobcat::Canvas_ {
        // std::vector<Point *> points;
        // std::vector<Shape *> shapes;
        std::vector<Layer> layers;

        // TODO: history
        History<CanvasRecord> history;

        Shape *selectedShape;

        template<typename RecordValue>
        void _createHistory(CANVAS_RECORD_ACTION actionType, RecordValue actionValue) {
            if (actionValue == CANVAS_RECORD_CREATE_SHAPE) {
                
            }
        };

        int _focusedLayerIndex;

        void _sortLayers() {
            
        };

        void _createLayer() {
            
        }
        
        // event handlers
        void _onMouseUpEventCb(bobcat::Widget* sender, float mouseX, float mouseY) {
            std::cout << "internal mouse up event cb" << std::endl;
            onMouseUpEvent(sender, mouseX, mouseY);
        };
        void _onMouseDownEventCb(bobcat::Widget* sender, float mouseX, float mouseY) {
            std::cout << "internal mouse down event cb" << std::endl;
            onMouseDownEvent(sender, mouseX, mouseY);
        };
        void _onMouseDragEventCb(bobcat::Widget* sender, float mouseX, float mouseY) {
            std::cout << "internal mouse drag event cb" << std::endl;
            onMouseDragEvent(sender, mouseX, mouseY);
        };
        

    protected:
        virtual void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        virtual void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) {};
        aiero::Toolbar* toolbar;
    public:
        Canvas(int x, int y, int w, int h) : Canvas_(x, y, w, h) {
            selectedShape = nullptr;
            toolbar = nullptr; // need to be initialized by the derived class
            _focusedLayerIndex = -1;
        };

        void initEvents() {
            ON_MOUSE_UP(this, aiero::Canvas::_onMouseUpEventCb);
            ON_MOUSE_DOWN(this, aiero::Canvas::_onMouseDownEventCb);
            ON_DRAG(this, aiero::Canvas::_onMouseDragEventCb);
        };

        // layer system
        void changeLayerFocus(int index) {
            if ((int) layers.size()-1 < index || index < 0) throw std::to_string(index) + " layer index does not exist";
            _focusedLayerIndex = index;
        };

        int focusedLayerIndex() const { return _focusedLayerIndex; };
        
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
        

        // required
        void render() {
            // const int x = 0;
            // const int y = 0;
            // const int width = 1;
            // const int height = 1;
            
            // glBegin(GL_POLYGON);
            //     glVertex2f(x,           y + height / 2.0f); // top
            //     glVertex2f(x + width / 2.0f, y);            // right
            //     glVertex2f(x,           y - height / 2.0f); // bottom
            //     glVertex2f(x - width / 2.0f, y);            // left
            // glEnd();
        };
    };
}; // namespace aiero

#endif