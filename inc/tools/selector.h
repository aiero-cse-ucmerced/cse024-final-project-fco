// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef SELECTOR_H
#define SELECTOR_H

#include "../Enums.h"
#include "../Tool.h"
#include <FL/Enumerations.H>
#include <FL/Fl_PNG_Image.H>
#include <bobcat_ui/button.h>

class SelectorTool : public aiero::Tool {
    TOOL _name = SELECTOR;

    public:
        SelectorTool() {
            _obj = new bobcat::Button(0, 0, 45, 45, "");
            _obj->box(FL_NO_BOX); // no background when the button is idle
            _obj->down_box(FL_NO_BOX); // no background when the button is pressed
            _obj->clear_visible_focus(); // removes the focus box when the mouse clicks on the button
            _obj->image(new Fl_PNG_Image("assets/selector.png"));
            _obj->align(FL_ALIGN_IMAGE_BACKDROP); // necessary for image to align center
        };

        // optional
        void onClick(float x, float y) override;
        // void onMouseDown(float x, float y) override;
        // void onMouseUp(float x, float y) override;

        // required
        // LEAD TEAM NOTE: images cannot be colored due to FLTK limitations; thus, we will highlight the tool by changing its box frame.

        void _activate() override {
            _obj->box(FL_ROUNDED_BOX);
            _obj->down_box(FL_ROUNDED_BOX);
            _obj->redraw();
        };

        void _deactivate() override {
            _obj->box(FL_NO_BOX);
            _obj->down_box(FL_NO_BOX);
            _obj->redraw();

        };
};

#endif