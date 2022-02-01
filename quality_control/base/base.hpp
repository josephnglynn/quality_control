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

	namespace internal
	{
		enum _exit_type
		{
			do_not_exit,
			exit
		};

		template<typename T>
		static constexpr bool new_line_for_output()
		{
			return false;
		}

		template<typename T>
		struct OutputValue
		{
			explicit OutputValue(const T& t) : data(t) {}
			const T& data;

			constexpr friend std::ostream& operator<<(std::ostream& os, const OutputValue<T>& output_value)
			{
				if constexpr (new_line_for_output<T>())
				{
					os << "\n"
					   << LOGGER_INTERVAL << output_value.data;
				}
				else
				{
					os << output_value.data;
				}

				return os;
			}
		};

		template<typename T>
		constexpr inline OutputValue<T> output_error_value(const T& t)
		{
			return OutputValue<T>(t);
		}

		template<_exit_type exit_on_error, typename A, typename B>
		constexpr bool on_unexpected_result(const char* test_name, const A& a, const B& b)
		{
			logger::error("Error running test: ", test_name);
			logger::error("Where a" LOGGER_PURPLE " ( type:",
				abi::__cxa_demangle(typeid(a).name(), nullptr, nullptr, nullptr), "):",
				output_error_value(a));
			logger::error("And b" LOGGER_PURPLE " ( type:",
				abi::__cxa_demangle(typeid(b).name(), nullptr, nullptr, nullptr), "):",
				output_error_value(b));
			if constexpr (exit_on_error == exit) std::exit(EXIT_CODE_ON_ERROR);
			return false;
		}

	}

	template<typename T>
	struct CastedTypeData
	{
		explicit CastedTypeData(const T& t) : data(t) {}
		const T& data;
	};

	template<typename A, typename C>
	constexpr inline decltype(auto) do_cast_if_not_void(const A& a)
	{
		if constexpr (std::is_void<C>::value || std::is_same<A, C>::value) return CastedTypeData<A>(a);
		if constexpr (!std::is_void<C>::value && !std::is_same<A, C>::value) return CastedTypeData<C>(static_cast<const C&>(a));
	}

}// namespace quality_control

#endif//QUALITY_CONTROL_HPP
