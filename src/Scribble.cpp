#include <Scribble.h>

Scribble::Scribble(float x, float y, Color color){
    points.push_back(new Point(x, y, color));
}

void Scribble::draw()const{
    for (size_t i = 0; i < points.size(); i++) {
        points[i]->draw();
    }
}

Scribble::~Scribble(){
    for (size_t i = 0; i < points.size(); i++) {
        delete points[i];
    }
}