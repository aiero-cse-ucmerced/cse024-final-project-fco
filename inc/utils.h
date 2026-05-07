// AIERO-FINAL-PROJECT-FCO FILE (Do not remove tag)
// Refer to aiero.space/final-project-fco


#ifndef UTILS
#define UTILS

#include <cmath>
#include <vector>
#include <type_traits>

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


    // (1) vector of type, (2) class type for copy constructor
    // example: Shape*, Shape*
    template <typename D>
    std::vector<D> deepCloneVector(const std::vector<D>& lhs) {
        using Pointee = std::remove_pointer_t<D>;

        static_assert(std::is_polymorphic_v<Pointee>,
                    "deepCloneVector expects a pointer to a polymorphic base");
        
        std::vector<D> rhs;
        rhs.reserve(lhs.size());

        for (auto p : lhs) {
            rhs.push_back(p ? static_cast<D>(p->clone()) : nullptr);
        }

        return rhs;
    }
}

#endif