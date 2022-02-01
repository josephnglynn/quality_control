//
// Created by joseph on 30/01/2022.
//

#ifndef QUALITY_CONTROL_EQUALITY_HPP
#define QUALITY_CONTROL_EQUALITY_HPP
#include "../base/base.hpp"
#include <type_traits>

namespace quality_control
{

	template<_exit_type exit_type, typename A, typename B>
	constexpr inline bool _equality(const A& a, const B& b)
	{
		if (a == b) return true;
		return _on_unexpected_result<exit_type>(__FUNCTION__, a, b);
	}

	template<typename C = void, typename A, typename B>
	constexpr inline bool check_equal(const A& a, const B& b)
	{
		return _equality<_exit_type::do_not_exit>( _quality_control_do_cast_if_not_void(a, C),  _quality_control_do_cast_if_not_void(b, C));
	}

	template<typename C = void, typename A, typename B>
	constexpr inline bool assert_equal(const A& a, const B& b)
	{
		return _equality<_exit_type::exit>( _quality_control_do_cast_if_not_void(a, C),  _quality_control_do_cast_if_not_void(b, C));
	}
}// namespace quality_control

template<typename C = void, typename A, typename B>
constexpr inline bool CHECK_EQUAL(const A& a, const B& b)
{
	return quality_control::check_equal<C>(a, b);
}

template<typename C = void, typename A, typename B>
constexpr inline bool ASSERT_EQUAL(const A& a, const B& b)
{
	return quality_control::assert_equal<C>(a, b);
}

#endif//QUALITY_CONTROL_EQUALITY_HPP
