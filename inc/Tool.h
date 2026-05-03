// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TOOL_H
#define TOOL_H

#include <bobcat_ui/bobcat_ui.h>
#include <bobcat_ui/button.h>
#include <bobcat_ui/image.h>
#include <iostream>
#include <ostream>
#include <string>

#include "Enums.h"

namespace aiero {
    class Tool {
        bool _active = false;
        TOOL _name;

        double _size;
        

        virtual void onClick(float x, float y) {};
        virtual void onMouseDown(float x, float y) {};
        virtual void onMouseUp(float x, float y) {};
        virtual void onMouseDrag(float x, float y) {};

        virtual void _activate() = 0;
        virtual void _deactivate() = 0;

        protected:
            bobcat::Button* _obj; // derived class is expected to make this

        public:
            Tool() {
                // do nothing
                _obj = nullptr; // make sure this occurs
            };

            virtual bool isCore() { return false; };

            TOOL name() const { return _name; };
            void name(TOOL tlname) { _name = tlname; };
            float size() const { return _size; };
            void size(float newSize) { _size = newSize; };

            bobcat::Button* obj() const { return _obj; };
            bobcat::Button* object() const { return _obj; };

            virtual ~Tool() { if (_obj == nullptr) return; delete _obj; };

            bool active() const { return _active; };

            void activate() {
                if (_active)
                    return;
                _active = true;
                _activate();
            };

            void deActivate() {
                if (!_active)
                    return;
                _active = false;
                _deactivate();
            };

            void toggle() {
                if (!_active)
                    activate();
                else
                    deActivate();
            }

            // event handlers
            void onMouseUpCb(float mouseX, float mouseY) { onMouseUp(mouseX, mouseY); };
            void onMouseDownCb(float mouseX, float mouseY) { onClick(mouseX, mouseY); onMouseDown(mouseX, mouseY); };
            void onMouseDragCb(float mouseX, float mouseY) { onMouseDrag(mouseX, mouseY); };

            friend std::ostream &operator<<(std::ostream &os, const aiero::Tool &tl);
    };

    inline std::ostream &operator<<(std::ostream &os, const aiero::Tool &tl) {

        os << "Tool " << tl._name << " | status: " << std::to_string(tl._active);
        os << std::endl;

        return os;
    };

};

#endif