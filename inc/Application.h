// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef APPLICATION_H
#define APPLICATION_H

#include "Canvas.h"
#include "mainwindow.h"
#include <bobcat_ui/all.h>

class Application : public bobcat::Application_ {
    bobcat::Window* mainWindow;

    aiero::MWDrawingCanvas* drawingCanvas;
    aiero::MWMenubar* mainWindowMenuBar;
    aiero::MWToolbar* mainWindowToolBar;
public:
    Application();
};

#endif

