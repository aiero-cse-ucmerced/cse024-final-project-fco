// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TOOLBAR_H
#define TOOLBAR_H

#include "Enums.h"
#include "Tool.h"
#include <FL/Enumerations.H>
#include <FL/Fl_Group.H>
#include <bobcat_ui/group.h>
#include <bobcat_ui/window.h>
#include <string>

namespace aiero {
    class Toolbar : public bobcat::Group {
        aiero::Tool* _focusedTool;
        
        std::vector<aiero::Tool*> tools;
        
        void _init(int x, int y, int w, int h) {
            // _obj = new bobcat::Window(x, y, w, h, ""); // derived classes will need to make it
            _obj = nullptr;
        }

        void _sortItems() {
            int startingY = 0;
            
            for (aiero::Tool* tl : tools) {
                tl->obj()->position(0, startingY);
                startingY += tl->obj()->h() + (tools.back() != tl ? 5 : 0);
            };

            _obj->redraw();
        };

        void _onClickEvent(bobcat::Widget* sender) {
            sender->clear_visible_focus();
            if (_focusedTool != nullptr && _focusedTool->obj() == sender) return;
            
            if (_focusedTool) {
                _focusedTool->deActivate();
                std::cout << "focused tool deactivated" << std::endl;
            }

            _focusedTool = nullptr;

            for (aiero::Tool* tl : tools) {
                if (tl->obj() == sender) {
                    tl->activate();
                    
                    _focusedTool = tl;
                    
                    break;
                }
            }
        };

        protected:
            bobcat::Window* _obj; // needs to be passed to derived classes
        
        public:
            Toolbar() : Group(0, 0, 0, 0) {
                _focusedTool = nullptr;
                
                _init(0, 0, 0, 0);
            };
            
            Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
                _focusedTool = nullptr;
                _init(x, y, w, h);
            };

            ~Toolbar() {
                _focusedTool = nullptr;
                
                for (aiero::Tool* tl : tools) {
                    delete tl;
                };

                tools.clear();

                delete _obj;
            };

            void parent(bobcat::Window* newParent) {
                if (_obj == nullptr) throw "Toolbar window was not created during initialization";
                newParent->add(_obj);
            };

            void color(Fl_Color flColor) {
                if (_obj == nullptr) throw "Toolbar window was not created during initialization";
                _obj->color(flColor);
            };

            void addItem(aiero::Tool* tool) {
                if (_obj == nullptr) throw "Toolbar window was not created during initialization";
                if (tool->obj() == nullptr) throw "Tool " + std::to_string(tool->name()) + " object was not created during initialization";
                
                tools.push_back(tool);
                
                // std::cout << "1" << std::endl;
                bobcat::Group::add(tool->obj());
                
                _obj->add(tool->obj());
                // std::cout << "2" << std::endl;
                ON_CLICK(tool->obj(), Toolbar::_onClickEvent);
                // std::cout << "3" << std::endl;
                
                _sortItems();
            };

            const bobcat::Window* obj() const { return _obj; };

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