#include <GL/gl.h>
#include "../inc/Color.h"
#include "../inc/shapers/rectangle.h"

void Rectangle::draw() {
    glColor3f(color.r() / 255.0, color.g() / 255.0, color.b() / 255.0);

    glBegin(GL_POLYGON);
    glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}
