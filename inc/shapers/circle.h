// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#ifndef CIRCLE_H
#define CIRCLE_H

#include "../Enums.h"
#include "../Tool.h"

#include "../Shape.h"
#include "../Application.h"

#include "../tools/CoreTool.h"

class Circle : public Shape {
    public:
        void draw() override {
            
        };
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            return false;
        };

};

class CircleTool : public aiero::CoreTool {
    TOOL _name = SHAPE_CIRCLE;

public:
    CircleTool() {
        // TODO
    };;

    // optional
    void onMouseDown(float x, float y) override;
    void onMouseUp(float x, float y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif