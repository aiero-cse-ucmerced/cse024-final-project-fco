#ifndef TOOL_H
#define TOOL_H

#include <bobcat_ui/bobcat_ui.h>
#include <iostream>
#include <ostream>
#include <string>

#include <Enums.h>

struct ToolSize {
    float size = 0.0;
};

namespace aiero {
    class Tool {
        bool _active = false;
        TOOL _name;

        bobcat::Widget *tlbtn; // derived class is expected to make this

        virtual void onClick() {};
        virtual void onMouseDown() {};
        virtual void onMouseUp() {};

        virtual void _activate() = 0;
        virtual void _deactivate() = 0;

        public:
            Tool() {
                // _name = "unknown"; // tool name must remain lowercase
            };

            virtual ~Tool() { delete tlbtn; };

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
                if (_active)
                    activate();
                else
                    deActivate();
            }

            

            friend std::ostream &operator<<(std::ostream &os, const aiero::Tool &tl);
    };

    inline std::ostream &operator<<(std::ostream &os, const aiero::Tool &tl) {

        os << "Tool " << tl._name << " | status: " << std::to_string(tl._active);
        os << std::endl;

        return os;
    };

};

#endif