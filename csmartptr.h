#pragma once

#include <stdio.h>

typedef enum cpointer_result {
	CMEMORYLOCATION_ERR
} cpointer_result;

typedef struct cpointer {
	cpointer_result(*destroy)(void* ptr);
	void* ptr;
	size_t refCount;
} cpointer;

typedef struct creference {
	cpointer* memory;
} creference;



