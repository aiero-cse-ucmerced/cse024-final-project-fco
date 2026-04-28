#ifndef APPLICATION_H
#define APPLICATION_H

#include <bobcat_ui/all.h>
#include <Canvas.h>

class Application : public bobcat::Application_ {
    bobcat::Window* window;
    Canvas* canvas;
    Fl_Color_Chooser *colorSelector = new Fl_Color_Chooser(500,0,300,143,0);
    
    void onCanvasMouseDown(bobcat::Widget* sender, float x, float y);
    void onCanvasMouseDrag(bobcat::Widget* sender, float x, float y);

public:
    Application();
};

#endif

