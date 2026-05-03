// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SELECTOR_H
#define SELECTOR_H

#include "../Enums.h"
#include "../Tool.h"
#include <FL/Fl_PNG_Image.H>
#include <bobcat_ui/button.h>

class SelectorTool : public aiero::Tool {
    TOOL _name = SELECTOR;

    public:
        SelectorTool() {
            _obj = new bobcat::Button(0, 0, 45, 45, "selector");
            _obj->image(new Fl_PNG_Image(""));
        };

        // optional
        void onClick(int x, int y) override;
        // void onMouseDown(int x, int y) override;
        // void onMouseUp(int x, int y) override;

        // required
        void _activate() override {

        };

        void _deactivate() override {

        };
};

#endif