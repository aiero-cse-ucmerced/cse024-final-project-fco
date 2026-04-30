// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Enums.h"
#include "../Tool.h"

#include "../Shape.h"

class Circle : public Shape {
    public:
        Circle();
        void draw() override {
            
        };
        
        bool checkMouseBounds() const override {
            
        };
};

class CircleTool : public aiero::Tool {
    TOOL _name = SHAPE_CIRCLE;

public:
    CircleTool();

    // optional
    void onClick(int x, int y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif