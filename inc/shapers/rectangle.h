// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"

class RectangleTool : public aiero::CoreTool {
    TOOL _name = SHAPE_RECTANGLE;

    public:
        RectangleTool() {
            // change whatever
        };

        // optional
        void onMouseDown(float x, float y) override;
        void onMouseUp(float x, float y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif