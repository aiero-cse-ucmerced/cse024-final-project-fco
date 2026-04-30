// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef PAINTBRUSH_H
#define PAINTBRUSH_H

#include "../Enums.h"
#include "../Tool.h"

class PaintBrushTool : public aiero::Tool {
    TOOL _name = PAINT_BRUSH;

    public:
        PaintBrushTool(); // to be implemented in the source files

        // optional
        void onClick(int x, int y) override;
        void onMouseDown(int x, int y) override;
        void onMouseUp(int x, int y) override;

        // required
        void _activate() override {

        };

        void _deactivate() override {

        };
};

#endif