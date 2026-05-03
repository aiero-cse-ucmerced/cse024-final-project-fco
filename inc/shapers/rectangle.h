// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"

class RectangleTool : public aiero::Tool {
    TOOL _name = SHAPE_RECTANGLE;

    public:
        RectangleTool() {
            // change whatever
        };

        // optional
        void onClick(int x, int y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif