//
// Created by joseph on 01/02/2022.
//

#ifndef QUALITY_CONTROL_QUALITY_CONTROL_SUITE_SUITE_HPP
#define QUALITY_CONTROL_QUALITY_CONTROL_SUITE_SUITE_HPP
#include "../base/base.hpp"
#include "../test/test.hpp"
#include <string>

namespace quality_control
{
	namespace internal
	{

		struct TestStorageList
		{
			Test* current;
			Test* next;
		};



		class SuiteInstance
		{
		public:

		private:
			TestStorageList m_test_wrapper;
		};
	}

}

#define _quality_control_internal_top_level_suite_name Suite
#define _quality_control_internal_join_namespaces(a, b) a::b
#define SUITE(SUITE_NAME) namespace _quality_control_internal_join_namespaces(_quality_control_internal_top_level_suite_name, SUITE_NAME) {        \
                                namespace internal    {                                                                                            \
                                    constexpr inline const char * get_name() { return #SUITE_NAME; }                                            \
                                }                                                                                                                \
                          }                                                                                                                    \
                          namespace _quality_control_internal_join_namespaces(_quality_control_internal_top_level_suite_name, SUITE_NAME)

#endif //QUALITY_CONTROL_QUALITY_CONTROL_SUITE_SUITE_HPP

