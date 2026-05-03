// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"

class TriangleTool : public aiero::Tool {
    TOOL _name = SHAPE_TRIANGLE;

    public:
        TriangleTool() {
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