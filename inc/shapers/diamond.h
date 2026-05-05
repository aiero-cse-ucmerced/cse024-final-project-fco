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
    Diamond()
        : Shape(0.0, 0.0f), width(0.15), height(0.15)
    {
        _color = Color(0.0f, 0.0f, 0.0f);
    }

    Diamond(float x, float y, float w, float h, const Color& c)
        : Shape(x, y), width(w), height(h)
    {
        _color = c;
    }

  void draw() override;
  bool checkMouseBounds(float mouseX, float mouseY) const override {

    return false;
}

private:
    float width;
    float height;
};

    

class DiamondTool : public aiero::CoreTool {
    TOOL _name = SHAPE_DIAMOND;

public:
    DiamondTool() {}

    //optional
    void onMouseDown(float x, float y) override;

    
    void _activate() override {}
    void _deactivate() override {}
};

#endif
