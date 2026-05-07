// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef COLOR_H
#define COLOR_H

#include <cmath>
#include <iostream>
#include "utils.h"

// max value up to 1.0
struct BaseColor {
    float r;
    float g;
    float b;
};

class Color {
    float _r, _g, _b; // up to 255 values

public:
    Color(int r, int g, int b) : _r(r), _g(g), _b(b) {
      _r = utils::clamp<int>(r, 0, 255);
      _g = utils::clamp<int>(g, 0, 255);
      _b = utils::clamp<int>(b, 0, 255);
    };
    
    Color(float r, float g, float b) : _r(r), _g(g), _b(b) {
      _r = utils::clamp<float>(r, 0, 255);
      _g = utils::clamp<float>(g, 0, 255);
      _b = utils::clamp<float>(b, 0, 255);
    };

    float r() const { return _r; };
    float g() const { return _g; };
    float b() const { return _b; };
    
    BaseColor toBase() {
        return {_r/255, _g/255, _b/255};
    };

    friend std::ostream &operator<<(std::ostream &os, const Color& color);
};

inline std::ostream &operator<<(std::ostream &os, const Color& color) {
    os << color.r() << ", " << color.g() << ", " << color.b();
    // os << std::endl;

    return os;
};
    
#endif