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

        void linkTabVisibility(bobcat::MenuItem *mitem, bobcat::Widget *widget) {
            if (linkedMenuItems.find(mitem) != linkedMenuItems.end()) throw mitem->label() + " menu item is already linked to a widget";
            linkedMenuItems[mitem] = widget;
            ON_CLICK(mitem, MWMenubar::_onLinkVisibility);
            _updateLinkVisibility(mitem, widget);
        };
    };

    class MWSidePanel : public bobcat::Group {
        bobcat::Window* sidePanel;
        
        bobcat::Window* colorPanelWindow;
        bobcat::Window* sizePanelWindow;
        bobcat::Window* layerPanelWindow;

    public:
        MWSidePanel(int x, int y, int w, int h);

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
        // bobcat::Window* _obj;
        aiero::Tool *selectorTool;
        aiero::Tool *paintBrushTool;
        aiero::Tool *eraserTool;

        // Shapes
        aiero::Tool *circleTool;
        aiero::Tool *pentagonTool;
        aiero::Tool *rectangleTool;
        aiero::Tool *starTool;
        aiero::Tool *diamondTool;
        aiero::Tool *triangleTool;

    public:
        MWToolbar(int x, int y, int w, int h);
    };

    class MWDrawingCanvas : public aiero::Canvas {
        void onMouseUpEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            const aiero::Tool* focusedTool = toolbar->focusedTool();
            if (focusedTool == nullptr) return;
            
            std::cout << "mouse up on canvas" << std::endl;
        };
        void onMouseDownEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            const aiero::Tool* focusedTool = toolbar->focusedTool();
            if (focusedTool == nullptr) return;
            
            tool->onClickCb(mouseX, mouseY);
            std::cout << "mouse down on canvas" << std::endl;
        };
        void onMouseDragEvent(bobcat::Widget* sender, float mouseX, float mouseY) override {
            
        };
    public:
        MWDrawingCanvas(int x, int y, int w, int h, aiero::Toolbar* tb) : Canvas(x, y, w, h) {
            toolbar = tb;
            this->end();
        };
    };
} // namespace aiero

#endif