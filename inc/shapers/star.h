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
    float outerRadius = 0.12f;
    float innerRadius = 0.12f * 0.4f;

    Star(float x, float y, float outerR, float innerR, const Color& c)
        : Shape(x, y),
          outerRadius(outerR),
          innerRadius(innerR)
    {
        _color = c;
    }

    void draw() override;

    bool checkMouseBounds(float mouseX, float mouseY) const override {
        const int VERTICES = 10;
        const float PI = 3.141592;
        const float TWO_PI = 2 * PI;
        const float startAngle = PI * 0.5;

        float px[VERTICES];
        float py[VERTICES];

        for(int i = 0; i < VERTICES; i ++){
        float r;
        if(i % 2 ==0){
            r = outerRadius;
        } else {
            r = innerRadius;
        }

        
        //converted deg to rad
        float angle = startAngle + i * (TWO_PI / float(VERTICES)); 
        float vx = _x + r * cos(angle);
        float vy = _y + r * sin(angle);

        px[i] = vx;
        py[i] = vy;
        }

        //Help from AI Assist
        bool inside = false;
        for (int i = 0, j = VERTICES - 1; i < VERTICES; j = i++) {
            if (((py[i] > mouseY) != (py[j] > mouseY)) &&
                (mouseX < (px[j] - px[i]) * (mouseY - py[i]) / (py[j] - py[i] + 0.000001f) + px[i])) {
                inside = !inside;
            }
        }
        return inside;
    }
};
class StarTool : public aiero::CoreTool {
    TOOL _name = SHAPE_STAR;

public:
    StarTool() {}

    void onMouseDown(float x, float y) override;

    void _activate() override {}
    void _deactivate() override {}
};
#endif

