//
// Created by joseph on 30/01/2022.
//

#include <quality_control/quality_control.hpp>
#include <utils.hpp>

SUITE(awesome_test_123)
{
}

int main()
{

	// Equality of varying unsigned types.
	utils::test_numbers<int8_t>([](int8_t a, int8_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<int16_t>([](int16_t a, int16_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<int32_t>([](int32_t a, int32_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<int64_t>([](int64_t a, int64_t b) { return CHECK_EQUAL(a, b); });

	// Equality of varying signed sizes.
	utils::test_numbers<uint8_t>([](uint8_t a, uint8_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<uint16_t>([](uint16_t a, uint16_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<uint32_t>([](uint32_t a, uint32_t b) { return CHECK_EQUAL(a, b); });
	utils::test_numbers<uint64_t>([](uint64_t a, uint64_t b) { return CHECK_EQUAL(a, b); });

	// Some signed tests cast signed to unsigned --> make sure we don't use negative values for signed int.
	utils::test_numbers<uint8_t, int8_t, false>([](uint8_t a, int8_t b) { return CHECK_EQUAL<uint8_t>(a, b); });
	utils::test_numbers<uint16_t, int16_t, false>([](uint16_t a, int16_t b) { return CHECK_EQUAL<uint16_t>(a, b); });
	utils::test_numbers<uint32_t, int32_t, false>([](uint32_t a, int32_t b) { return CHECK_EQUAL<uint32_t>(a, b); });
	utils::test_numbers<uint64_t, int64_t, false>([](uint64_t a, int64_t b) { return CHECK_EQUAL<uint64_t>(a, b); });

	/*
	LEAVE THIS COMMENTED, casting from unsigned to a signed int is implementation defined ==> therefore there will be a warning here when this library is compiled with certain compiler flags.

 	utils::test_numbers<uint8_t, int8_t>([](uint8_t a, int8_t b) { CHECK_EQUAL<int8_t>(a, b); });
	utils::test_numbers<uint16_t, int16_t>([](uint16_t a , int16_t b) { CHECK_EQUAL<int16_t>(a, b); });
	utils::test_numbers<uint32_t, int32_t>([](uint32_t a, int32_t b) { CHECK_EQUAL<int32_t>(a, b); });
	utils::test_numbers<uint64_t, int64_t>([](uint64_t a, int64_t b) { CHECK_EQUAL<int64_t>(a, b); });
	*/

	// Big to small.
	utils::test_numbers<int16_t, int8_t>([](int64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });
	utils::test_numbers<int32_t, int8_t>([](int64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });
	utils::test_numbers<int64_t, int8_t>([](int64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });

	utils::test_numbers<uint16_t, uint8_t>([](uint64_t a, uint8_t b) { return CHECK_EQUAL<uint8_t>(a, b); });
	utils::test_numbers<uint32_t, uint8_t>([](uint64_t a, uint8_t b) { return CHECK_EQUAL<uint8_t>(a, b); });
	utils::test_numbers<uint64_t, uint8_t>([](uint64_t a, uint8_t b) { return CHECK_EQUAL<uint8_t>(a, b); });

	// Big unsigned to small signed
	utils::test_numbers<uint16_t, int8_t, false>([](uint64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });
	utils::test_numbers<uint32_t, int8_t, false>([](uint64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });
	utils::test_numbers<uint64_t, int8_t, false>([](uint64_t a, int8_t b) { return CHECK_EQUAL<int8_t>(a, b); });

	utils::test_string<std::string::value_type, std::string::value_type>([](auto a, auto b) { CHECK_EQUAL(a, b); });

	// QUICKLY TEST GLOBAL NAMESPACE FUNCTIONS
	utils::test_numbers<int>([](auto a, auto b) {
		return CHECK_EQUAL(a, b);
	});
	utils::test_numbers<int>([](auto a, auto b) {
		return CHECK_EQUAL(a, b);
	});

	return 0;
}