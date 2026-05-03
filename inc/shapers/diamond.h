// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef DIAMOND_H
#define DIAMOND_H

#include "../Enums.h"
#include "../Tool.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"

class Diamond : public Shape {
    public:
        void draw() override {
            
        };
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            return false;
        };

};

class DiamondTool : public aiero::CoreTool {
    TOOL _name = SHAPE_DIAMOND;

public:
    DiamondTool() {
        // TODO
    };

    // optional
    void onMouseDown(float x, float y) override;
    void onMouseUp(float x, float y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif