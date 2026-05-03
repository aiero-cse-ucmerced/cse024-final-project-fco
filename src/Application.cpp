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
    mainWindow = new Window(100, 100, 900+250, 600, "Paintshop");

    menuBar = new MWMenubar(mainWindow->w(), mainWindow->h());
    menuBar->parent(mainWindow);
    
    toolBar = new MWToolbar(0, 40, 45, mainWindow->h() - 80);
    toolBar->parent(mainWindow);
    toolBar->color(mainWindow->color());
    // toolBar->color(FL_RED);

    sidePanel = new MWSidePanel(mainWindow->w() - 300, 25, 300, mainWindow->h() - 25);
    sidePanel->color(FL_GREEN);
    sidePanel->parent(mainWindow);
    // sidePanel->show();
    
    // cout << "side parent: " << sidePanel->parent()->label() << endl;
    
    drawingCanvas = new MWDrawingCanvas(200, 50, mainWindow->h() - (50*2), mainWindow->h() - (50*2), toolBar);
    // last

    try {
        menuBar->linkTabVisibility((*menuBar)["View/Toolbar"], (bobcat::Widget*) toolBar->obj());
        menuBar->linkTabVisibility((*menuBar)["View/Color Picker"], (bobcat::Widget*) (*sidePanel)["Color"]);
        menuBar->linkTabVisibility((*menuBar)["View/Size"], (bobcat::Widget*) (*sidePanel)["Size"]);
        menuBar->linkTabVisibility((*menuBar)["View/Layers"], (bobcat::Widget*) (*sidePanel)["Layers"]);
    } catch (std::string err) {
      cout << "The error says: " << err << endl;  
    }

    mainWindow->add(drawingCanvas);
    drawingCanvas->initEvents();
    
    mainWindow->show();
}