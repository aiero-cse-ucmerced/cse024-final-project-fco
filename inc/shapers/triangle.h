// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"
#include <cmath>

class Triangle : public Shape {
    double pi;
    public:
        Triangle(){
            pi = std::acos(-1.0);
            _x = 0.0;
            _y = 0.0;
            _color = {0,0,0};
            size = 10;
        }

        Triangle(float x, float y, int s, Color color){
            pi = std::acos(-1.0);
            _x = x;
            _y = y;
            _color = color;
            size = s;
        }
        void draw() override;
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            float x1 = _x;
            float y1 = _y + size;
            float x2 = _x - size * std::sin(pi / 3);
            float y2 = _y - size * std::cos(pi / 3);
            float x3 = _x + size * std::sin(pi / 3);
            float y3 = y2;

            auto sign = [](float px, float py, float ax, float ay, float bx, float by) {
            return (px - bx) * (ay - by) - (ax - bx) * (py - by);
            };

            float d1 = sign(mouseX, mouseY, x1, y1, x2, y2);
            float d2 = sign(mouseX, mouseY, x2, y2, x3, y3);
            float d3 = sign(mouseX, mouseY, x3, y3, x1, y1);

            bool has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
            bool has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
            return !(has_neg && has_pos);
    };

};

class TriangleTool : public aiero::CoreTool {
    TOOL _name = SHAPE_TRIANGLE;

    public:
        TriangleTool() {
            _obj = new bobcat::Button(0, 0, 45, 45, "");
            _obj->box(FL_NO_BOX); // no background
            _obj->image(new Fl_PNG_Image("assets/triangle.png"));
            _obj->align(FL_ALIGN_IMAGE_BACKDROP); // necessary for image to align center
        };

        // optional
        void onMouseDown(float x, float y) override;

        // required
        void _activate() override {};
        void _deactivate() override {};
};

#endif