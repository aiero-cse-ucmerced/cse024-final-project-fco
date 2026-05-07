// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef PAINTBRUSH_H
#define PAINTBRUSH_H

#include "../Enums.h"
#include "../Tool.h"

#include "CoreTool.h"

class PaintBrushTool : public aiero::CoreTool {
    TOOL _name = PAINT_BRUSH;

    public:
        PaintBrushTool() {
            _obj = new bobcat::Button(0, 0, 45, 45, "");
            _obj->box(FL_NO_BOX); // no background
            _obj->image(new Fl_PNG_Image("assets/paintbrush.png"));
            _obj->align(FL_ALIGN_IMAGE_BACKDROP); // necessary for image to align center
        }; // to be implemented in the source files

        // optional
        void onMouseDown(float x, float y) override;
        void onMouseUp(float x, float y) override;
        void onMouseDrag(float x, float y) override;

        // required
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