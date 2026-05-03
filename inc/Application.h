// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Canvas.h"
#include "mainwindow.h"
#include <bobcat_ui/all.h>

class Application : public bobcat::Application_ {
    bobcat::Window *mainWindow;

    aiero::MWDrawingCanvas *drawingCanvas;
    aiero::MWSidePanel *sidePanel;
    aiero::MWMenubar *menuBar;
    aiero::MWToolbar *toolBar;

    // canvas events
    void onCanvasMouseDown(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseUp(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseDrag(bobcat::Widget* sender, float x, float y);
public:
    Application();
};

#endif
