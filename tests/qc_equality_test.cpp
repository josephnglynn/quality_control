//
// Created by joseph on 30/01/2022.
//
#define LOGGER_ALWAYS_OUTPUT

#include <logger/logger.cpp>
#include <quality_control/quality_control.hpp>
#include <utils.hpp>

int main()
{
	logger::info("Starting equality tests");

	//equality of varying unsigned types
	utils::test_numbers<uint8_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint16_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint32_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint64_t>([](auto a, auto b) { quality_control::test_equal(a, b); });

	//equality of varying signed sizes
	utils::test_numbers<int8_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<int16_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<int32_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<int64_t>([](auto a, auto b) { quality_control::test_equal(a, b); });

	//some signed tests
	utils::test_numbers<uint8_t, int8_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint16_t, int16_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint32_t, int32_t>([](auto a, auto b) { quality_control::test_equal(a, b); });
	utils::test_numbers<uint64_t, int64_t>([](auto a, auto b) { quality_control::test_equal(a, b); });

	utils::test_string<std::string::value_type, std::string::value_type>([](auto a, auto b) { quality_control::test_equal(a, b); });



}