// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Canvas.h"
#include "Menubar.h"
#include "Toolbar.h"
#include "tools/CoreTool.h"

#include <FL/Enumerations.H>
#include <FL/Fl_Group.H>
#include <FL/fl_draw.H>
#include <algorithm>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/textbox.h>
#include <bobcat_ui/window.h>
#include <cmath>
#include <unordered_map>

namespace aiero {
    class MWMenubar : public aiero::Menubar {
        // internal
        aiero::Canvas* Canvas;

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

            std::cout << "onlink triggered" << std::endl;
            
            bobcat::Widget *menuWidget = linkedMenuItems[(bobcat::MenuItem *)menuItemClicked];

            if (menuWidget->visible())
                menuWidget->hide();
            else menuWidget->show();

            _updateLinkVisibility((bobcat::MenuItem *)menuItemClicked, menuWidget);
            std::cout << "onlink updated visibility" << std::endl;
        };

        void _updateLinkVisibility(bobcat::MenuItem *mitem,
                                bobcat::Widget *menuWidget) {
            if (menuWidget->visible()) {
                // std::cout << "color green" << std::endl;
                // mitem->color(FL_GREEN);
                // mitem->label("a " + mitem->label());
                mitem->redraw();
                return;
            }

            std::cout << "color grey" << std::endl;
            // mitem->color(FL_BACKGROUND_COLOR);
            // mitem->label(mitem->label().substr(2, mitem->label().length()-3));
            mitem->redraw();
        }

    public:
        MWMenubar(int w, int h); // defined in source files
        void internalCanvas(aiero::Canvas* c) { if (Canvas != nullptr) return; Canvas = c; };
        
        void linkTabVisibility(bobcat::MenuItem *mitem, bobcat::Widget *widget) {
            if (linkedMenuItems.find(mitem) != linkedMenuItems.end()) throw mitem->label() + " menu item is already linked to a widget";
            linkedMenuItems[mitem] = widget;
            ON_CLICK(mitem, MWMenubar::_onLinkVisibility);
            _updateLinkVisibility(mitem, widget);
        };
    };

    class MWSidePanel : public bobcat::Group {
        aiero::Canvas* Canvas;
        bobcat::Window* sidePanel;
        
        bobcat::Window* colorPanelWindow;
        bobcat::Window* sizePanelWindow;
        bobcat::Window* layerPanelWindow;

        void _addWindowLabel(bobcat::Window* window, const std::string& label) {
            bobcat::TextBox* tbox = new bobcat::TextBox(0, 0, 70, 25, label);
            tbox->align(FL_ALIGN_CENTER);
            tbox->box(FL_BORDER_BOX);
            tbox->parent(window);
            window->add(tbox);
        };
    public:
        MWSidePanel(int x, int y, int w, int h);
        void internalCanvas(aiero::Canvas* c) { if (Canvas != nullptr) return; Canvas = c; };

        bobcat::Window* operator[](const std::string &subWindow) {
            if (subWindow == "Color") return colorPanelWindow;
            if (subWindow == "Size") return sizePanelWindow;
            if (subWindow == "Layers") return layerPanelWindow;
            
            throw subWindow + " does not exist as a frame of the side panel";
        }

        void parent(bobcat::Window* newParent) { newParent->add(sidePanel); };
        void color(Fl_Color flColor) { bobcat::Group::color(flColor); sidePanel->redraw(); };
        // void bobcat::
    };

    class MWToolbar : public aiero::Toolbar {
        // internal
        aiero::Canvas* Canvas;
        
        // bobcat::Window* _obj;
        aiero::CoreTool *selectorTool;
        aiero::CoreTool *paintBrushTool;
        aiero::CoreTool *eraserTool;

        // Shapes
        aiero::CoreTool *circleTool;
        aiero::CoreTool *pentagonTool;
        aiero::CoreTool *rectangleTool;
        aiero::CoreTool *starTool;
        aiero::CoreTool *diamondTool;
        aiero::CoreTool *triangleTool;
        
    public:
        MWToolbar(int x, int y, int w, int h);

        void internalCanvasForCoreTools(aiero::Canvas* c) {
            selectorTool->internalCanvas(c);
            paintBrushTool->internalCanvas(c);
            eraserTool->internalCanvas(c);

            // suddenly shapers need internal access to Canvas too
            circleTool->internalCanvas(c);
            diamondTool->internalCanvas(c);
            pentagonTool->internalCanvas(c);
            rectangleTool->internalCanvas(c);
            starTool->internalCanvas(c);
            triangleTool->internalCanvas(c);
        }
    };

    class MWDrawingCanvas : public aiero::Canvas {
    public:
        void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            std::cout << "mouse up on canvas" << std::endl;
            aiero::Tool* focusedTool = toolbar->focusedTool();
            if (focusedTool == nullptr) return;

            focusedTool->onMouseUpCb(mouseX, mouseY);
            
        };
        void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            std::cout << "mouse down on canvas" << std::endl;
            aiero::Tool* focusedTool = toolbar->focusedTool();
            if (focusedTool == nullptr) return;
            
            focusedTool->onMouseDownCb(mouseX, mouseY);
        };
        void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            std::cout << "mouse drag on canvas" << std::endl;
            aiero::Tool* focusedTool = toolbar->focusedTool();
            if (focusedTool == nullptr) return;
            
            focusedTool->onMouseDragCb(mouseX, mouseY);
        };
        
        MWDrawingCanvas(int x, int y, int w, int h, aiero::Toolbar* tb) : Canvas(x, y, w, h) {
            toolbar = tb;
            this->end();
        };
    };
} // namespace aiero

#endif