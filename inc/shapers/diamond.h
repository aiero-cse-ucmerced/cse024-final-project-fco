// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef DIAMOND_H
#define DIAMOND_H

#include "../Enums.h"
#include "../Tool.h"

#include "../Shape.h"

class Diamond : public Shape {
    public:
        Diamond();
        ~Diamond() {

        };
        
        void draw() override {
            
        };
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            return false;
        };

};

class DiamondTool : public aiero::Tool {
    TOOL _name = SHAPE_DIAMOND;

public:
    DiamondTool() {
        // TODO
    };

    // optional
    void onClick(int x, int y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif