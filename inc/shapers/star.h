// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef STAR_H
#define STAR_H

#include "../Tool.h"
#include "../Enums.h"

class StarTool : public aiero::Tool {
    TOOL _name = SHAPE_STAR;

    public:
        StarTool() {
            // change whatever
        };;

        // optional
        void onClick(int x, int y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif