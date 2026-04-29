// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#include "Menubar.h"
#include "Toolbar.h"
#include <FL/Fl_Group.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>
#include <unordered_map>

#include "mainwindow.h"

using namespace std;
using namespace bobcat;
using namespace aiero;

MainWindowMenubar::MainWindowMenubar(int w, int h) : Menubar(w, h) {
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
};

MainWindowToolbar::MainWindowToolbar(int w, int h) {
    
}