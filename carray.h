#pragma once
#include <stdint.h>

struct carray {
	size_t m_length;
	size_t m_size;
	char* m_data;
};

enum carray_result {
	CARRAY_OK = 1,
	CARRAY_ERR_NULL = 0,
	CARRAY_ERR_BOUNDS = -1,
	CARRAY_ERR_OVERFLOW = -2,
	CARRAY_ERR_ALLOC = -3,
	CARRAY_ERR_SIZE = -4,
	CARRAY_ERR_LENGTH = -5,
};

typedef struct carray carray;
typedef enum carray_result carray_result;
typedef int(*carray_compare_func)(carray* a, carray* b);

carray_result carray_construct(carray* arr, size_t len, size_t size);
carray* carray_create(size_t len, size_t size);
carray* carray_copy(carray* arr);
carray_result carray_destroy(carray* arr);
carray_result carray_get_length(carray* arr, size_t* out);
carray_result carray_set_length(carray* arr, size_t size);
carray_result carray_get(carray* arr, size_t i, void* out, size_t size);
carray_result carray_set(carray* arr, size_t i, const void* in, size_t size);
carray_result carray_clear(carray* arr); 
carray_result carray_fill(carray* arr, const void* in, size_t size); 
//carray_result carray_compare(carray* arr, carray* in, carray_compare_func func);
