// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#include "Canvas.h"
#include "mainwindow.h"
#include <Application.h>
#include <FL/Enumerations.H>

using namespace std;
using namespace bobcat;
using namespace aiero;

Application::Application() {
    mainWindow = new Window(100, 100, 800, 600, "Paintshop");

    mainWindowMenuBar = new MWMenubar(mainWindow->w(), mainWindow->h());
    mainWindowMenuBar->parent(mainWindow);
    
    mainWindowToolBar = new MWToolbar(0, 40, 45, mainWindow->h() - 80);
    mainWindowToolBar->parent(mainWindow);
    mainWindowToolBar->color(FL_RED);
    
    drawingCanvas = new MWDrawingCanvas(50, 50, mainWindow->w() - (50*2), mainWindow->h() - (50*2));

    // last
    mainWindowMenuBar->linkTabVisibility((*mainWindowMenuBar)["View/Toolbar"], (bobcat::Widget*) mainWindowToolBar->obj());
    

    mainWindow->show();
}