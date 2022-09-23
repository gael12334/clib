#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "carray.h"
#include "ctest.h"

int main() {
	int value = 20;
	carray_result r;
	carray* arr = carray_create(10, sizeof(int));
	ctest_expect_nonnull_ptr(arr);

	r = carray_set(arr, 0, &value, sizeof(int));
	ctest_expect_result_to_succeed(r);

	r = carray_get(arr, 11, &value, sizeof(int));
	ctest_expect_result_to_succeed(r);

	printf("result: %i\nvalue: %i", r, value);

	ctest_end;
	getchar();
	getchar();

	return 0;
}