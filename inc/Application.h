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
public:
    Application();

    void undo(bobcat::Widget* sender);
    void redo(bobcat::Widget* sender);
};

#endif
