// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef UTILS
#define UTILS

#include <cmath>
#include <vector>

namespace utils {
    template <typename A> // where A is a math data type (int, double, float, etc..)
    A clamp(A currentValue, A minimum, A maximum) {
        return currentValue < minimum ? minimum : std::min(currentValue, maximum);
    };


    template <typename B>
    std::vector<B> copyVector(const std::vector<B> &lhs) {
        std::vector<B> rhs = {};
        rhs.reserve(lhs.size()); // reserves the same memory capacity as lhs

        for (const auto& a : lhs) {
            rhs.push_back(a);    
        }
        
        return rhs;
    };
    
    template <typename B, typename C>
    std::vector<B> copyVector(const std::vector<C> &lhs) {
        std::vector<B> rhs = {};
        rhs.reserve(lhs.size()); // reserves the same memory capacity as lhs

        for (const auto& a : lhs) {
            rhs.push_back(a);    
        }
        
        return rhs;
    };
}

#endif