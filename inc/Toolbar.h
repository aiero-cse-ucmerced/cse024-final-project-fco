// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Enums.h"
#include "Tool.h"
#include <FL/Fl_Group.H>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>

namespace aiero {
    class Toolbar : public bobcat::Group {
        bobcat::Window* _obj;
        aiero::Tool* _focusedTool;
        
        std::vector<aiero::Tool*> tools;
        
        void _init(int x, int y, int w, int h) {
            _obj = new bobcat::Window(x, y, w, h, "");
            _obj->end();
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

        virtual void _onClickEvent(bobcat::Widget* sender) {
            
        }
        
        public:
            Toolbar() : Group(0, 0, 0, 0) {
                _focusedTool = nullptr;
                
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
                _focusedTool = nullptr;

                delete _obj;
            };

            void parent(bobcat::Window* newParent) {
                _obj->parent(newParent);
            }

            void addItem(aiero::Tool* tool) {
                tools.push_back(tool);
                Fl_Group::add(tool->obj());
                
                tool->obj()->parent(_obj);
                ON_CLICK(tool->obj(), Toolbar::_onClickEvent);
                
                _sortItems();
                _obj->redraw();
            };

            aiero::Tool* focusedTool() const {
                return _focusedTool;
            };

            void focusTool(TOOL tlname) {
                if (_focusedTool != nullptr && _focusedTool->name() == tlname) return;

                for (aiero::Tool* tl : tools) {
                    if (tl->name() == tlname) {
                        if (_focusedTool != nullptr)
                            _focusedTool->deActivate();
                        
                        tl->activate();
                        break;
                    }
                };
            };

            int x() const { return _obj->x(); };
            int y() const { return _obj->y(); };
            int w() const { return _obj->w(); };
            int h() const { return _obj->h(); };

            
    };
};

#endif