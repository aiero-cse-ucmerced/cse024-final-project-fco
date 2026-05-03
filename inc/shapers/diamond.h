// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef DIAMOND_H
#define DIAMOND_H

#include "../Enums.h"
#include "../Tool.h"

class DiamondTool : public aiero::Tool {
    TOOL _name = SHAPE_TRAPEZOID;

public:
    DiamondTool();

    // optional
    void onClick(int x, int y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif