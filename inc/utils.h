#ifndef UTILS
#define UTILS

#include <cmath>

namespace utils {
    template <typename A> // where A is a math data type (int, double, float, etc..)
    A clamp(A currentValue, A minimum, A maximum) {
        return currentValue < minimum ? minimum : std::min(currentValue, maximum);
    }
}

#endif