#include "carray.h"
#include "cbasedef.h"
#include <stdlib.h>
#include <string.h>

#define throw_if_null_length(len)       if (len == 0) { return CARRAY_ERR_LENGTH; } 
#define throw_if_null_size(size)	    if (size == 0) { return CARRAY_ERR_SIZE; }
#define throw_if_invalid_alloc(ptr)	    if (ptr == NULL) { return CARRAY_ERR_ALLOC; }
#define throw_if_invalid_index(i, max)  if ((i) >= (max)) { return CARRAY_ERR_BOUNDS; }
#define throw_if_invalid_size(s, arr_s) if ((s) != (arr_s)) { return CARRAY_ERR_SIZE; };

carray_result carray_construct(carray* arr, size_t len, size_t size, )
{
	throw_if_null(arr);
	throw_if_null_length(len);
	throw_if_null_size(size);

	if (arr->m_data)
		free(arr->m_data);

	arr->m_length = len;
	arr->m_size = size;
	arr->m_data = malloc(len * size);
	throw_if_null(arr->m_data);

	return success;
}

carray* carray_create(size_t len, size_t size) {
	if (len == 0) { return NULL; }
	if (size == 0) { return NULL; }

	carray* arr = malloc(sizeof(carray));
	if (arr == NULL) { return NULL; }

	

	return arr;
}

carray* carray_copy(carray* arr) {
	if (arr == NULL) { return NULL; }
	if (arr->m_length == 0) { return NULL; }
	if (arr->m_size == 0) { return NULL; }
	
	carray* carr = malloc(sizeof(carray));
	if (carr == NULL) { return NULL; }

	carr->m_length = arr->m_length;
	carr->m_size = arr->m_size;
	carr->m_data = malloc(arr->m_length * arr->m_size);
	if (carr->m_data == NULL) { return NULL; }

	return arr;
}

carray_result carray_destroy(carray* arr) {
	throw_if_null(arr);
	throw_if_null(arr->m_data);
	
	free(arr->m_data);
	free(arr);
	return success;
}

carray_result carray_get_length(carray* arr, size_t* out) {
	throw_if_null(arr);
	throw_if_null(out);
	*out = arr->m_length;
	return success;
}

carray_result carray_set_length(carray* arr, size_t len) {
	throw_if_null(arr);
	throw_if_null_length(len);

	char* data = realloc(arr->m_data, len * arr->m_size);
	throw_if_invalid_alloc(arr);
	
	arr->m_data = data; 
	arr->m_length = len;
	return success;
}

carray_result carray_get(carray* arr, size_t i, void* out, size_t size) {
	throw_if_null(arr);
	throw_if_null(out);
	throw_if_invalid_index(i, arr->m_length);
	throw_if_invalid_size(size, arr->m_size);
	
	const void* element = &arr->m_data[i * arr->m_size];
	memcpy(out, element, size);
	return success;
}

carray_result carray_set(carray* arr, size_t i, const void* in, size_t size) {
	throw_if_null(arr);
	throw_if_null(in);
	throw_if_invalid_index(i, arr->m_length);
	throw_if_invalid_size(size, arr->m_size);
	
	void* element = &arr->m_data[i * arr->m_size];
	memcpy(element, in, size);
	return success;
}

carray_result carray_clear(carray* arr) {
	throw_if_null(arr);
	throw_if_null_length(arr->m_length);
	throw_if_null_size(arr->m_size);

	memset(arr->m_data, 0, arr->m_size * arr->m_length);
	return success;
}

carray_result carray_fill(carray* arr, const void* in, size_t size) {
	throw_if_null(arr);
	throw_if_null_length(arr->m_length);
	throw_if_null_size(arr->m_size);
	throw_if_invalid_size(size, arr->m_size);
	throw_if_null(in);

	const void* data; 
	for (size_t i = 0; i < arr->m_length; i++) {
		data = &arr->m_data[i * arr->m_size];
		memcpy(data, in, size);
	}

	return success;
}

/*
carray_result carray_compare(carray* arr, carray* in, carray_compare_func func) {
	return success;
}
*/