// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Menubar.h"
#include "Toolbar.h"
#include <FL/Fl_Group.H>
#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/group.h>
#include <bobcat_ui/menu.h>
#include <bobcat_ui/window.h>
#include <unordered_map>

namespace aiero {
    class MainWindowMenubar : public aiero::Menubar {
        bobcat::MenuItem* viewMenuTabToolbar;
        bobcat::MenuItem* viewMenuTabColorPicker;
        bobcat::MenuItem* viewMenuTabSize;
        bobcat::MenuItem* viewMenuTabLayers;
        
        bobcat::MenuItem* layerMenuTabDeleteShape;
        bobcat::MenuItem* layerMenuTabBringLayerFront;
        bobcat::MenuItem* layerMenuTabBringLayerBack;
        bobcat::MenuItem* layerMenuTabBringLayerUp;
        bobcat::MenuItem* layerMenuTabBringLayerDown;
        
        bobcat::MenuItem* editMenuTabUndo;
        bobcat::MenuItem* editMenuTabRedo;
        bobcat::MenuItem* editMenuTabDeleteCurrentLayer;
        bobcat::MenuItem* editMenuTabDeleteClearCanvas;

        std::unordered_map<bobcat::MenuItem*, bobcat::Window*> linkedMenuItems;

        void _onLinkVisibility(bobcat::Widget* menuItemClicked) {
            if (linkedMenuItems.find((bobcat::MenuItem*) menuItemClicked) == linkedMenuItems.end()) return;
            bobcat::Window* menuWindow = linkedMenuItems[(bobcat::MenuItem*) menuItemClicked];

            
        };

        void _linkTabVisibility(bobcat::MenuItem* mitem, bobcat::Window* menuWindow) {
            linkedMenuItems[mitem] = menuWindow;
            ON_CLICK(mitem, MainWindowMenubar::_onLinkVisibility);
        };

        public:
            MainWindowMenubar(int w, int h); // defined in source files
    };

    class MainWindowSidePanel : public bobcat::Group {
        
    };

    class MainWindowToolbar : public aiero::Toolbar {
        aiero::Tool* selectorTool;
        aiero::Tool* paintBrushTool;
        aiero::Tool* eraserTool;

        // Shapes
        aiero::Tool* circleTool;
        aiero::Tool* pentagonTool;
        aiero::Tool* rectangleTool;
        aiero::Tool* starTool;
        aiero::Tool* trapezoidTool;
        aiero::Tool* triangleTool;

        public:
            MainWindowToolbar(int w, int h); // will be initialized in src
    };
    
    class MainWindow : public bobcat::Group {
        int _x, _y, _w, _h;
        
        bobcat::Window* _obj;
        MainWindowMenubar _toolBar;

        void _init() {
            _obj = new bobcat::Window(_x, _y, _w, _h, "Main Window");
        };

        public:
            MainWindow(int x, int y, int w, int h) : Group(x, y, w, h), _toolBar(w, h) {
                _x = x;
                _y = y;
                _w = w;
                _h = h;
                
                _init();
                
                Fl_Group::add(_obj);
            };

            void show() { _obj->show(); };
            void hide() { _obj->hide(); };
            void add(bobcat::Widget* sender) {
                Fl_Group::add(sender);
                _obj->add(sender);
            };
    };
}

#endif