#pragma once
#include <stdio.h>

#define ctest_end end_test_label:
#define ctest_fail_output(msg, parameter, ...) printf("[fail] line: %i, function: %s\nerror: %s " ##parameter , __LINE__, __func__, msg, __VA_ARGS__)
#define ctest_value_type_int "%ld"
#define ctest_value_type_float "%lf"
#define ctest_value_type_ptr "%p"
#define ctest_value_type_str "%s"

#define ctest_expect(value, to_be, value_type)	\
	if((value) != (to_be)) { ctest_fail_output("value was not expected.", ##value_type " != " ##value_type, value, to_be); goto end_test_label; }

#define ctest_expect_null_ptr(ptr)		\
	if((ptr) != NULL) { ctest_fail_output("expected a null pointer.", ctest_value_type_ptr, ptr); goto end_test_label; }

#define ctest_expect_nonnull_ptr(ptr)	\
	if((ptr) == NULL) { ctest_fail_output("not expected a null pointer.", ctest_value_type_ptr, ptr); goto end_test_label; }

#define ctest_expect_result_to_succeed(r)   \
	if((r) <= 0) { ctest_fail_output("operation failed.", ctest_value_type_int, r); goto end_test_label; }
