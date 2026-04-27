#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Menubar.h"
#include "Toolbar.h"
#include <FL/Fl_Group.H>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>

namespace aiero {
    class MainWindowMenubar : public aiero::Menubar {

        public:
            MainWindowMenubar(int w, int h) : Menubar(w, h) {
                
            };
    };

    class MainWindowToolbar : public aiero::Toolbar {
        Tool

        public:
            MainWindowToolbar(int w, int h) {
                addItem(aiero::Tool *tool)
            }
    };
    
    class MainWindow : public bobcat::Group {
        int _x, _y, _w, _h;
        
        bobcat::Window* _obj;
        MainWindowMenubar _toolBar;
        

        void _initToolbar() {
            
        };

        void _init() {
            _obj = new bobcat::Window(400, 500, "Main Window");
        };

        public:
            MainWindow(int x, int y, int w, int h) : Group(x, y, w, h), _toolBar(w, h) {
                Fl_Group::add(_obj);
                
                _x = x;
                _y = y;
                _w = w;
                _h = h;
                
                _initToolbar();
                _init();
            };

            void show() { _obj->show(); };
            void hide() { _obj->hide(); };
            void add(bobcat::Widget* sender) {
                Fl_Group::add(sender);
                window->add()
            };
    };
}

#endif