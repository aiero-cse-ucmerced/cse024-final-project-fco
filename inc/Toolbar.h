// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Tool.h"
#include <FL/Fl_Group.H>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>

namespace aiero {
    class Toolbar : public bobcat::Group {
        int _x, _y, _w, _h;
        bobcat::Window* _obj;
        
        std::vector<aiero::Tool*> tools;
        
        void _init(int x, int y, int w, int h) {
            _x = 0;
            _y = 0;
            _w = 0;
            _h = 0;

            _obj = new bobcat::Window(_x, _y, _w, _h, "");
            _obj->parent(nullptr);
        }

        void _sortItems() {
            int startingY = 0;
            
            for (aiero::Tool* tl : tools) {
                tl->obj()->position(0, startingY);
                startingY += tl->obj()->h() + (tools.back() != tl ? 5 : 0);
            };

            _obj->redraw();
        };
        
        public:
            Toolbar() : Group(0, 0, 0, 0) {
                _init(0, 0, 0, 0);
            };
            
            Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
                _init(x, y, w, h);
            };

            ~Toolbar() {
                for (aiero::Tool* tl : tools) {
                    delete tl;
                };

                tools.clear();
            };

            void parent(bobcat::Window* newParent) {
                _obj->parent(newParent);
            }

            void addItem(aiero::Tool* tool) {
                tools.push_back(tool);
                Fl_Group::add(tool->obj());
                
                tool->obj()->parent(_obj);

                _sortItems();
            };
            
            int x() const { return _obj->x(); };
            int y() const { return _obj->y(); };
            int w() const { return _obj->w(); };
            int h() const { return _obj->h(); };

            
    };
};

#endif