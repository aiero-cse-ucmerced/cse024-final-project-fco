// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Tool.h"
#include "../Enums.h"

class TriangleTool : public aiero::Tool {
    TOOL _name = SHAPE_TRIANGLE;

    public:
        TriangleTool();

        // optional
        void onClick(int x, int y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif