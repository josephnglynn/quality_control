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
	utils::test_numbers<int8_t>([](int8_t a, int8_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<int16_t>([](int16_t a, int16_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<int32_t>([](int32_t a, int32_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<int64_t>([](int64_t a, int64_t b) { quality_control::check_equal(a, b); });

	//equality of varying signed sizes
	utils::test_numbers<uint8_t>([](uint8_t a, uint8_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<uint16_t>([](uint16_t a, uint16_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<uint32_t>([](uint32_t a, uint32_t b) { quality_control::check_equal(a, b); });
	utils::test_numbers<uint64_t>([](uint64_t a, uint64_t b) { quality_control::check_equal(a, b); });

	//some signed tests cast signed to unsigned
	utils::test_numbers<uint8_t, int8_t>([](uint8_t a, int8_t b) { quality_control::check_equal<uint8_t>(a, b); });
	utils::test_numbers<uint16_t, int16_t>([](uint16_t a , int16_t b) { quality_control::check_equal<uint16_t>(a, b); });
	utils::test_numbers<uint32_t, int32_t>([](uint32_t a, int32_t b) { quality_control::check_equal<uint32_t>(a, b); });
	utils::test_numbers<uint64_t, int64_t>([](uint64_t a, int64_t b) { quality_control::check_equal<uint64_t>(a, b); });


	uint64_t a = 0;
	int64_t b = 0;
	CHECK_EQUAL<uint64_t>(a, b);
	/*
	LEAVE THIS COMMENTED, casting from unsigned to a signed int is implementation defined ==> therefore there will be a warning here when this library is compiled.

 	utils::test_numbers<uint8_t, int8_t>([](uint8_t a, int8_t b) { quality_control::check_equal<int8_t>(a, b); });
	utils::test_numbers<uint16_t, int16_t>([](uint16_t a , int16_t b) { quality_control::check_equal<int16_t>(a, b); });
	utils::test_numbers<uint32_t, int32_t>([](uint32_t a, int32_t b) { quality_control::check_equal<int32_t>(a, b); });
	utils::test_numbers<uint64_t, int64_t>([](uint64_t a, int64_t b) { quality_control::check_equal<int64_t>(a, b); });
    */

	//big to small
	utils::test_numbers<uint64_t, uint8_t>([](uint64_t a, uint8_t b) { quality_control::check_equal(a, b); });



	utils::test_string<std::string::value_type, std::string::value_type>([](auto a, auto b) { quality_control::check_equal(a, b); });


}