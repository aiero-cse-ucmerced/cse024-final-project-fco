#include <Application.h>
using namespace bobcat;

Application::Application() {
    window = new Window(25, 75, 400, 400, "Paintshop");

    textBox = new TextBox(0, 0, 100, 100, "Layout Order"); // related to layout order system

    window->end();

    window->show();
}
