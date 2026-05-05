// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef STAR_H
#define STAR_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"

class Star : public Shape {
    public:
    float outerRadius = 0.12;
    float innerRadius = 0.12 * 0.4;
   Star(float x, float y, float outerR, float innerR, const Color& c)
        :Shape(x, y),
          outerRadius(outerR),
          innerRadius(innerR)
    {
        _color = c;
    }

    
    void draw() override;
    bool checkMouseBounds(float mouseX, float mouseY) const override {
       
        float dx = mouseX - _x;
        float dy = mouseY - _y;
        return (dx * dx + dy * dy) <= (outerRadius * outerRadius);
    }
};

class StarTool : public aiero::CoreTool {
    TOOL _name = SHAPE_STAR;

    public:
        StarTool() {}

        // optional
        void onMouseDown(float x, float y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif
