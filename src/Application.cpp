// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#include "Canvas.h"
#include "mainwindow.h"
#include "Point.h"
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
    
    

    sidePanel = new MWSidePanel(mainWindow->w() - 300, 25, 300, mainWindow->h() - 25);
    sidePanel->color(FL_GREEN);
    sidePanel->parent(mainWindow);
    // sidePanel->show();
    
    // cout << "side parent: " << sidePanel->parent()->label() << endl;
    
    drawingCanvas = new MWDrawingCanvas(200, 50, mainWindow->h() - (50*2), mainWindow->h() - (50*2), toolBar);
    menuBar->internalCanvas(drawingCanvas);
    sidePanel->internalCanvas(drawingCanvas);
    
    // gives internal canvas permission to core tools
    toolBar->internalCanvasForCoreTools(drawingCanvas);

    try {
        menuBar->linkTabVisibility((*menuBar)["View/Toolbar"], (bobcat::Widget*) toolBar->obj());
        menuBar->linkTabVisibility((*menuBar)["View/Color Picker"], (bobcat::Widget*) (*sidePanel)["Color"]);
        menuBar->linkTabVisibility((*menuBar)["View/Size"], (bobcat::Widget*) (*sidePanel)["Size"]);
        menuBar->linkTabVisibility((*menuBar)["View/Layers"], (bobcat::Widget*) (*sidePanel)["Layers"]);

        ON_CLICK((*menuBar)["Edit/Undo"], Application::undo);
        ON_CLICK((*menuBar)["Edit/Redo"], Application::redo);
    } catch (std::string err) {
      cout << "The error says: " << err << endl;  
    }

    mainWindow->add(drawingCanvas);
    drawingCanvas->initEvents();
    
    // Point* p = new Point(0, 5);
    // p->changeSize(10);
    // drawingCanvas->addShape(p);
    // p->color(1,1,1);
    // Point* p2 = new Point(p);
    
    // cout << "p2 x: " << p2->x() << std::endl;
    // cout << "p2 y: " << p2->y() << std::endl;
    // cout << "p2 color: " << (*p2).color() << std::endl;
    
    mainWindow->show();
}

void Application::redo(bobcat::Widget* sender) {
  drawingCanvas->redoLayer();
}

void Application::undo(bobcat::Widget* sender) {
  drawingCanvas->undoLayer();
}