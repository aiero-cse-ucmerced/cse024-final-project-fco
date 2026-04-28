// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "../Tool.h"
#include "../Enums.h"

class TrapezoidTool : public aiero::Tool {
    TOOL _name = SHAPE_TRAPEZOID;

    public:
        TrapezoidTool();

        // optional
        void onClick(int x, int y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif