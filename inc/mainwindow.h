// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Canvas.h"
#include "Menubar.h"
#include "Toolbar.h"
#include <FL/Enumerations.H>
#include <FL/Fl_Group.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>
#include <unordered_map>

namespace aiero {
class MWMenubar : public aiero::Menubar {
    bobcat::MenuItem *viewMenuTabToolbar;
    bobcat::MenuItem *viewMenuTabColorPicker;
    bobcat::MenuItem *viewMenuTabSize;
    bobcat::MenuItem *viewMenuTabLayers;

    bobcat::MenuItem *layerMenuTabDeleteShape;
    bobcat::MenuItem *layerMenuTabBringLayerFront;
    bobcat::MenuItem *layerMenuTabBringLayerBack;
    bobcat::MenuItem *layerMenuTabBringLayerUp;
    bobcat::MenuItem *layerMenuTabBringLayerDown;

    bobcat::MenuItem *editMenuTabUndo;
    bobcat::MenuItem *editMenuTabRedo;
    bobcat::MenuItem *editMenuTabDeleteCurrentLayer;
    bobcat::MenuItem *editMenuTabDeleteClearCanvas;

    std::unordered_map<bobcat::MenuItem *, bobcat::Widget *> linkedMenuItems;

    void _onLinkVisibility(bobcat::Widget *menuItemClicked) {
        if (linkedMenuItems.find((bobcat::MenuItem *)menuItemClicked) ==
            linkedMenuItems.end())
            return;
        bobcat::Widget *menuWidget =
            linkedMenuItems[(bobcat::MenuItem *)menuItemClicked];

        _updateLinkVisibility((bobcat::MenuItem *)menuItemClicked, menuWidget);
    };

    void _updateLinkVisibility(bobcat::MenuItem *mitem,
                               bobcat::Widget *menuWidget) {
        if (menuWidget->visible()) {
            mitem->color(FL_GREEN);
            return;
        }

        mitem->color(FL_BACKGROUND_COLOR);
    }

public:
    MWMenubar(int w, int h); // defined in source files

    void linkTabVisibility(bobcat::MenuItem *mitem, bobcat::Widget *widget) {
        linkedMenuItems[mitem] = widget;
        ON_CLICK(mitem, MWMenubar::_onLinkVisibility);
        _updateLinkVisibility(mitem, widget);
    };
};

class MWSidePanel : public bobcat::Group {
    bobcat::Window *colorPanelWindow;
    bobcat::Window *sizePanelWindow;
    bobcat::Window *layerPanelWindow;

public:
    MWSidePanel();

    // void bobcat::
};

class MWToolbar : public aiero::Toolbar {
    // bobcat::Window* _obj;
    aiero::Tool *selectorTool;
    aiero::Tool *paintBrushTool;
    aiero::Tool *eraserTool;

    // Shapes
    aiero::Tool *circleTool;
    aiero::Tool *pentagonTool;
    aiero::Tool *rectangleTool;
    aiero::Tool *starTool;
    aiero::Tool *trapezoidTool;
    aiero::Tool *triangleTool;

public:
    MWToolbar(int x, int y, int w, int h); // will be initialized in src
};

class MWDrawingCanvas : public aiero::Canvas {
public:
    MWDrawingCanvas(int x, int y, int w, int h) : Canvas(x, y, w, h) {
        this->end();
    };
};

// class MainWindow : public bobcat::Group {
//     int _x, _y, _w, _h;

//     bobcat::Window* _obj;
//     MainWindowMenubar _toolBar;

//     void _init() {
//         _obj = new bobcat::Window(_x, _y, _w, _h, "Main Window");
//     };

//     public:
//         MainWindow(int x, int y, int w, int h) : Group(x, y, w, h),
//         _toolBar(w, h) {
//             _x = x;
//             _y = y;
//             _w = w;
//             _h = h;

//             _init();

//             Fl_Group::add(_obj);
//         };

//         void show() { _obj->show(); };
//         void hide() { _obj->hide(); };
//         void add(bobcat::Widget* sender) {
//             Fl_Group::add(sender);
//             _obj->add(sender);
//         };
// };
} // namespace aiero

#endif