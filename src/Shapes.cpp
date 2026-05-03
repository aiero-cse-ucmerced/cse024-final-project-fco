// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco

#include "Point.h"
#include "Tools.h"
#include "shapers/circle.h"
#include "shapers/pentagon.h"

void Point::draw() {
    glPointSize(size);
        
    const BaseColor bColor = _color.toBase();
    glColor3f(bColor.r, bColor.g, bColor.b);
    
    glBegin(GL_POINT);
        glVertex2f(_x, _y);
    glEnd();
}

// Pentagon::Pentagon() {
    
// }
// Circle::Circle() {
    
// }
// Circle::Circle() {
    
// }
// Circle::Circle() {
    
// }
// Circle::Circle() {
    
// }