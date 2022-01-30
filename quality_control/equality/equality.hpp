//
// Created by joseph on 30/01/2022.
//

#ifndef QUALITY_CONTROL_EQUALITY_HPP
#define QUALITY_CONTROL_EQUALITY_HPP
#include "../base/base.hpp"

namespace quality_control {
    template<typename A, typename B>
    constexpr void test_equal(A& a, B& b)
    {
        if (a == b) return;
        _on_unexpected_result<do_not_exit>(__FUNCTION__, a, b);
    }

    template<typename T>
    constexpr void test_equal(T& a, T& b)
    {
        test_equal<T, T>(a, b);
    }

    template<typename A, typename B>
    constexpr void assert_equal(A& a, B& b)
    {
        if (a == b) return;
        _on_unexpected_result<exit>(__FUNCTION__, a, b);
    }

    template<typename T>
    constexpr void assert_equal(T& a, T& b)
    {
        test_equal<T, T>(a, b);
    }
}

#endif //QUALITY_CONTROL_EQUALITY_HPP
