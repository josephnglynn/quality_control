//
// Created by joseph on 30/01/2022.
//

#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#define LOGGER_ALWAYS_OUTPUT
#include <functional>
#include <logger/logger.hpp>
#include <string>

namespace utils
{

	inline void error()
	{
		logger::error("Error in test case");
		std::exit(-1);
	}

	template<typename A, typename B, bool negative = true>
	constexpr inline void test_numbers(std::function<bool(A, B)> func)
	{
		A a;
		B b;

		if constexpr (std::is_signed_v<A> && negative)
		{
			a = -8;
		}
		else
		{
			a = 0;
		}

		if constexpr (std::is_signed_v<B> && negative)
		{
			b = -8;
		}
		else
		{
			b = 0;
		}

		if (!func(a, b)) error();

		a = b = 2;
		if (!func(a, b)) error();

		a = b = 1;
		if (!func(a, b)) error();

		a = b = 4;
		if (!func(a, b)) error();
	}

	template<typename T>
	constexpr inline void test_numbers(std::function<bool(T, T)> func)
	{
		return test_numbers<T, T>(func);
	}

	template<typename A, typename B>
	constexpr inline void test_string(std::function<void(const std::basic_string<A>& a,
														 const std::basic_string<B>& b)>
										  func)
	{
		std::basic_string<A> a = (const A*)"Test_String";
		std::basic_string<B> b = (const B*)"Test_String";
		func(a, b);
	}

}// namespace utils

#endif//TESTS_UTILS_H
