// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef ERASER_H
#define ERASER_H

#include "../Enums.h"
#include "../Tool.h"

class SelectorTool : public aiero::Tool {
    TOOL _name = SELECTOR;

    public:
        SelectorTool();

        // optional
        void onClick(int x, int y) override;
        // void onMouseDown(int x, int y) override;
        // void onMouseUp(int x, int y) override;

        // required
        void _activate() override {

        };

        void _deactivate() override {

        };
};

#endif