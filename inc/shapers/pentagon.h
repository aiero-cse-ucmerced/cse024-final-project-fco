// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef PENTAGON_H
#define PENTAGON_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"
#include <cmath>
#include <FL/Enumerations.H>
#include <FL/Fl_PNG_Image.H>
#include <bobcat_ui/button.h>

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
        Shape* clone() override {
            return new Pentagon(*this);
        };
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            bool hasNeg = false;
            bool hasPos = false;

            for (int i = 0; i < 5; i++) {
                const double a1 = (pi / 2.0) + i * (2.0 * pi / 5.0);
                const double a2 = (pi / 2.0) + ((i + 1) % 5) * (2.0 * pi / 5.0);

                const float ax = _x + size * std::cos(a1);
                const float ay = _y + size * std::sin(a1);
                const float bx = _x + size * std::cos(a2);
                const float by = _y + size * std::sin(a2);

                const float cross = (mouseX - ax) * (by - ay) - (mouseY - ay) * (bx - ax);
                hasNeg = hasNeg || (cross < 0);
                hasPos = hasPos || (cross > 0);
            }

            if (hasNeg && hasPos){ 
            return false;
            }
            return true;
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
