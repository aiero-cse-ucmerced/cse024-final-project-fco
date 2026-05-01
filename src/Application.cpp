// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#include "Canvas.h"
#include "mainwindow.h"
#include <Application.h>

using namespace std;
using namespace bobcat;
using namespace aiero;

Application::Application() {
    mainWindow = new Window(100, 100, 800, 600, "Paintshop");

    mainWindowToolBar = new MainWindowToolbar(0, 40, 45, mainWindow->h() - 80);

    drawingCanvas = new MainDrawingCanvas(50, 50, mainWindow->w() - (50*2), mainWindow->h() - (50*2));

    // last
    
    mainWindowMenuBar = new MainWindowMenubar(mainWindow->w(), mainWindow->h());
    mainWindowMenuBar->parent(mainWindow);

    mainWindowMenuBar->linkTabVisibility(mainWindowMenuBar[(std::string) "View/Toolbar"], mainWindowToolBar->obj())


    mainWindow->show();
}