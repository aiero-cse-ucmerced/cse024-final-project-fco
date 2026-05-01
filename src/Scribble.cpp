#include <Scribble.h>

Scribble::Scribble(){
    //
}

void Scribble::draw()const{
    for (size_t i = 0; i < points.size(); i++) {
        points[i]->draw();
    }
}

void Scribble::addPoint(float x, float y, Color color){
    points.push_back(new Point(x, y, color));
}
Scribble::~Scribble(){
    for (size_t i = 0; i < points.size(); i++) {
        delete points[i];
    }
    points.clear();
}