//
// Created by joseph on 30/01/2022.
//

#ifndef QUALITY_CONTROL_EQUALITY_HPP
#define QUALITY_CONTROL_EQUALITY_HPP
#include "../base/base.hpp"
#include <type_traits>

namespace quality_control
{

	template<typename A, typename B>
	constexpr inline bool _check_equal(const A& a, const B& b)
	{
		if (a == b) return true;
		return _on_unexpected_result<do_not_exit>(__FUNCTION__, a, b);
	}

	template<typename C = void, typename A, typename B>
	constexpr bool check_equal(const A& a, const B& b)
	{
		if constexpr (std::is_void_v<C>) return _check_equal(a, b);
		if constexpr (!std::is_void_v<C>) return _check_equal(std::is_same_v<A, C> ? a : static_cast<C>(a), std::is_same_v<B, C> ? b : static_cast<C>(b));
	}

	template<typename T>
	constexpr bool check_equal(const T& a, const T& b)
	{
		return _check_equal<T, T>(a, b);
	}

	template<typename A, typename B>
	constexpr bool assert_equal(const A& a, const B& b)
	{
		if (a == b) return true;
		return _on_unexpected_result<exit>(__FUNCTION__, a, b);
	}

	template<typename T>
	constexpr void assert_equal(const T& a, const T& b)
	{
		return check_equal<T, T>(a, b);
	}
}// namespace quality_control

template<typename C = void, typename A, typename B>
constexpr bool CHECK_EQUAL(const A& a, const B& b)
{
	return quality_control::check_equal<C>(a, b);
}
#endif//QUALITY_CONTROL_EQUALITY_HPP
