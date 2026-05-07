// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#include "Shapers.h"
#include "shapers/circle.h"
#include "shapers/diamond.h"
#include "shapers/pentagon.h"
#include "shapers/rectangle.h"
#include "shapers/star.h"
#include "shapers/triangle.h"

// CIRCLE

void CircleTool::onMouseDown(float x, float y) {
    
}

// PENTAGON

void PentagonTool::onMouseDown(float x, float y) {
    Pentagon *p = new Pentagon(x,y,10,{0,0,0});
    Canvas->addShape(p);
}

// RECTANGLE

void RectangleTool::onMouseDown(float x, float y) {
    
}

// STAR

void StarTool::onMouseDown(float x, float y) {
    
}

// DIAMOND

void DiamondTool::onMouseDown(float x, float y) {
    
}

// TRIANGLE

void TriangleTool::onMouseDown(float x, float y) {
    Triangle *t = new Triangle(x,y,10,{0,0,0});
    Canvas->addShape(t);
}