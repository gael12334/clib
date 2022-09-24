#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "carray.h"
#include "ctest.h"

void ctest_carray_good_results() {
	int value = 20;
	int value2 = -300;
	carray_result r;
	size_t s;

	carray* arr = carray_create(10, sizeof(int));
	ctest_expect_nonnull_ptr(arr);

	r = carray_set(arr, 0, &value, sizeof(int));
	ctest_expect_result_to_succeed(r);

	r = carray_get(arr, 9, &value, sizeof(int));
	ctest_expect_result_to_succeed(r);

	r = carray_get_length(arr, &s);
	ctest_expect_result_to_succeed(r);

	r = carray_set_length(arr, 20);
	ctest_expect_result_to_succeed(r);

	r = carray_set(arr, 11, &value, sizeof(int));
	ctest_expect_result_to_succeed(r);

	carray* c = carray_copy(arr);
	ctest_expect_nonnull_ptr(arr);

	r = carray_clear(arr);
	ctest_expect_result_to_succeed(r);

	r = carray_fill(arr, &value2, sizeof(int));
	ctest_expect_result_to_succeed(r);

	r = carray_destroy(arr);
	ctest_expect_result_to_succeed(r);

	ctest_test_pass;
	ctest_end;
}

int main() {
	ctest_carray_good_results();

	getchar();
	getchar();

	return 0;
}