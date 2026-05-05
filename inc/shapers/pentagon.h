// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef PENTAGON_H
#define PENTAGON_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"
#include <cmath>

class Pentagon : public Shape {
    double pi;
    public:
        Pentagon(){
            pi = std::acos(-1.0);
            _x = 0.0;
            _y = 0.0;
            _color = {0,0,0};
            size = 10;
        }

        Pentagon(float x, float y, int s, Color color){
            pi = std::acos(-1.0);
            _x = x;
            _y = y;
            _color = color;
            size = s;
        }
        void draw() override;
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            float dx = mouseX - _x;
            float dy = mouseY - _y;
            return dx * dx + dy * dy <= size * size;
        }   
        
};


class PentagonTool : public aiero::CoreTool {
    TOOL _name = SHAPE_PENTAGON;

public:
    PentagonTool()  {
        _obj = new bobcat::Button(0, 0, 45, 45, "");
            _obj->box(FL_NO_BOX); // no background
            _obj->image(new Fl_PNG_Image("assets/pentagon.png"));
            _obj->align(FL_ALIGN_IMAGE_BACKDROP); // necessary for image to align center
    };

    // optional
    void onMouseDown(float x, float y) override;

    // required
    void _activate() override {};
    void _deactivate() override {};
};

#endif