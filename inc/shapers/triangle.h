// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../Tool.h"
#include "../Enums.h"

#include "../Shape.h"
#include "../tools/CoreTool.h"

class Triangle : public Shape {
    double pi = std::acos(-1.0);
    public:
        Triangle(){
            _x = 0.0;
            _y = 0.0;
            _color = {0,0,0};
            size = 0.2;
        }

        Triangle(float x, float y, int _size, Color color){
            _x = x;
            _y = y;
            _color = color;
            size = _size;
        }
        void draw() override;
        
        bool checkMouseBounds(float mouseX, float mouseY) const override {
            if(mouseX <= _x && mouseY <= mouseY){
                return true;
            };
            return false;
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