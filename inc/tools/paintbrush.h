// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef PAINTBRUSH_H
#define PAINTBRUSH_H

#include "../Enums.h"
#include "../Tool.h"

class PaintBrushTool : public aiero::Tool {
    TOOL _name = PAINT_BRUSH;

    public:
        PaintBrushTool() {
            _obj = new bobcat::Button(0, 0, 45, 45, "");
            _obj->box(FL_NO_BOX); // no background
            _obj->image(new Fl_PNG_Image("assets/paintbrush.png"));
            _obj->align(FL_ALIGN_IMAGE_BACKDROP); // necessary for image to align center
        }; // to be implemented in the source files

        // optional
        void onClick(float x, float y) override;
        // void onMouseDown(float x, float y) override;
        // void onMouseUp(float x, float y) override;

        // required
        void _activate() override {

        };

        void _deactivate() override {

        };
};

#endif