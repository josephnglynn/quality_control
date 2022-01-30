//
// Created by joseph on 30/01/2022.
//

#ifndef TESTS_UTILS_H
#define TESTS_UTILS_H

#include <functional>
#include <string>

namespace utils
{

	template<typename A, typename B>
	constexpr inline void test_numbers(std::function<void(A, B)> func)
	{
		A a;
		B b;

		if (std::is_signed_v<A>)
		{
			a = -8;
		}
		else
		{
			a = 0;
		}

		if (std::is_signed_v<B>) {
			b = -8;
		} else {
			b = 0;
		}


		func(a, b);

		a = b = 2;
		func(a, b);

		a = b = 1;
		func(a, b);

		a = b = 4;
		func(a, b);
	}

	template<typename T>
	constexpr inline void test_numbers(std::function<void(T, T)> func)
	{
		return test_numbers<T, T>(func);
	}

	template<typename A, typename B>
	constexpr inline void test_string(std::function<void(const std::basic_string<A>& a, const std::basic_string<B>& b)> func)
	{
		std::basic_string<A> a = (const A*)"Test_String";
		std::basic_string<B> b = (const B*)"Test_String";
		func(a, b);
	}

}// namespace utils

#endif//TESTS_UTILS_H
