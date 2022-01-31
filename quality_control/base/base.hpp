//
// Created by joseph on 30/01/2022.
//

#ifndef QUALITY_CONTROL_HPP
#define QUALITY_CONTROL_HPP

#include <cxxabi.h>
#include <logger/logger.hpp>
#include <ostream>

#define EXIT_CODE_ON_ERROR 1

namespace quality_control
{

	enum _exit_on_error
	{
		do_not_exit,
		exit
	};

	template<typename T>
	static constexpr bool _new_line_for_output()
	{
		return false;
	}

	template<typename T>
	struct _output_value {
		const T* t;

		constexpr friend std::ostream& operator<<(std::ostream& os, const _output_value<T>& output_value)
		{
			if constexpr (_new_line_for_output<T>())
			{
				os << "\n"
				   << LOGGER_INTERVAL << *output_value.t;
			}
			else
			{
				os << *output_value.t;
			}

			return os;
		}
	};

	template<typename T>
	static _output_value<T> _output_error_value(const T& t)
	{
		_output_value<T> output_value;
		output_value.t = &t;
		return output_value;
	}

	template<_exit_on_error exit_on_error, typename A, typename B>
	constexpr bool _on_unexpected_result(const char* test_name, const A& a, const B& b)
	{
		logger::error("Error running test: ", test_name);
		logger::error("Where a" LOGGER_PURPLE " ( type:",
					  abi::__cxa_demangle(typeid(a).name(), nullptr, nullptr, nullptr), "):",
					  _output_error_value(a));
		logger::error("And b" LOGGER_PURPLE " ( type:",
					  abi::__cxa_demangle(typeid(b).name(), nullptr, nullptr, nullptr), "):",
					  _output_error_value(b));
		if constexpr (exit_on_error == exit) std::exit(EXIT_CODE_ON_ERROR);
		return false;
	}


}// namespace quality_control

#endif//QUALITY_CONTROL_HPP
