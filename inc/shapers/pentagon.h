// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef PENTAGON_H
#define PENTAGON_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"

class PentagonTool : public aiero::Tool {
    TOOL _name = SHAPE_PENTAGON;

public:
    PentagonTool()  {
        // TODO
    };

    // optional
    void onClick(int x, int y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif