#include <Application.h>
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 800, 400, "Paint Application");

    canvas = new Canvas(100, 0, 400, 400);

    window->add(canvas);
    window->add(colorSelector);
    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasMouseDrag);

    window->show();
}
void Application::onCanvasMouseDown(bobcat::Widget *sender, float x, float y){
    double red = colorSelector->r();
    double green = colorSelector->g();
    double blue = colorSelector->b();
    Color color = {float(red), float(green), float(blue)};
    canvas->addScribble(x,y,color);
    canvas->redraw();
}

void Application::onCanvasMouseDrag(bobcat::Widget *sender, float x, float y){
    double red = colorSelector->r();
    double green = colorSelector->g();
    double blue = colorSelector->b();
    Color color = {float(red), float(green), float(blue)};
    canvas->addScribble(x,y,color);
    canvas->redraw();
}

Application::~Application() {
    delete canvas;
    delete colorSelector;
    delete window;
}
