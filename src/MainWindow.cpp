// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#include "Menubar.h"
#include "Toolbar.h"
#include "shapers/circle.h"
#include "shapers/pentagon.h"
#include "shapers/rectangle.h"
#include "shapers/star.h"
#include "shapers/diamond.h"
#include "shapers/triangle.h"
#include "tools/eraser.h"
#include "tools/paintbrush.h"
#include "tools/selector.h"
#include <FL/Enumerations.H>
#include <FL/Fl_Group.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>
#include <system_error>
#include <unordered_map>
#include <bits/stdc++.h>

#include "mainwindow.h"

using namespace std;
using namespace bobcat;
using namespace aiero;

MWMenubar::MWMenubar(int w, int h) : Menubar(w, h) {
    viewMenuTabToolbar = addItem("View/Toolbar");
    viewMenuTabColorPicker = addItem("View/Color Picker");
    viewMenuTabSize = addItem("View/Size");
    viewMenuTabLayers = addItem("View/Layers");

    layerMenuTabDeleteShape = addItem("Layers/Delete Shape");
    layerMenuTabBringLayerFront = addItem("Layers/Layer Front");
    layerMenuTabBringLayerBack = addItem("Layers/Layer Back");
    layerMenuTabBringLayerUp = addItem("Layers/Layer Up");
    layerMenuTabBringLayerDown = addItem("Layers/Layer Down");

    editMenuTabUndo = addItem("Edit/Undo");
    editMenuTabRedo = addItem("Edit/Redo");
    editMenuTabDeleteCurrentLayer = addItem("Edit/Delete Current Layer");
    editMenuTabDeleteClearCanvas = addItem("Edit/Clear Canvas");

    // cout << "mw menubar init done" << endl;
};

MWToolbar::MWToolbar(int x, int y, int w, int h) {
    _obj = new bobcat::Window(x, y, w, h, "");
    // _obj->box(FL_NO_BOX);
    _obj->end();

    // Core tools
    selectorTool = new SelectorTool();
    eraserTool = new EraserTool();
    paintBrushTool = new PaintBrushTool();

    // Shapers
    circleTool = new CircleTool();
    pentagonTool = new PentagonTool();
    rectangleTool = new RectangleTool();
    starTool = new StarTool();
    diamondTool = new DiamondTool();
    triangleTool = new TriangleTool();
    
    addItem(selectorTool);
    addItem(eraserTool);
    addItem(paintBrushTool);

    // addItem(circleTool);
}

MWSidePanel::MWSidePanel(int x, int y, int w, int h)
    : bobcat::Group(x, y, w, h) {
    sidePanel = new Window(x, y, w, h, "side-panel");
    sidePanel->color(FL_GREEN);

    colorPanelWindow = new Window(0, 0, w, h * 0.4);
    colorPanelWindow->box(FL_BORDER_BOX);
    // TEAM TODO: create the implementation here
    // colorPanelWindow->color(sidePanel->color());
    
    colorPanelWindow->end();

    sizePanelWindow = new Window(0, colorPanelWindow->h(), w, h * 0.25);
    sizePanelWindow->box(FL_BORDER_BOX);
    // TEAM TODO: create the implementation here
    
    sizePanelWindow->end();

    layerPanelWindow =
        new Window(0, sizePanelWindow->y() + sizePanelWindow->h(), w, h * 0.35);
    layerPanelWindow->box(FL_BORDER_BOX);
    // TEAM TODO: create the implementation here
    layerPanelWindow->end();

    // end of side panel creation
    sidePanel->end();
}