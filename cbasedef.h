#pragma once
#include <string.h>

typedef int cresult;
#define CRESULT_OK 1
#define CRESULT_ERR_ALLOC 0
#define CRESULT_ERR_NULL -1

#define throw_if_null(ptr)              if (ptr == 0x0) { return CRESULT_ERR_NULL; }
#define throw_if_invalid_result(r)      if ((r) != 1) { return r; }
#define success	                        (CRESULT_OK)

typedef cresult(*cdestructor)(void* _this);

#define cdestructor_decl(ctype) \
cresult ctype##_destructor(void* _this);

#define cdestructor_default_decl(ctype) \
cresult ctype##_destructor(void* _this)

#define cdestructor_default_impl(ctype) \
cdestructor_default_decl(ctype) { \
	throw_if_null(ptr);      \
    return success;          \
}

typedef cresult(*ccopytor)(void* _this, void* ptr);

#define ccopytor_decl(ctype) \
cresult ctype##_copytor(void* _this, void* ptr)

#define ccopytor_default_decl(ctype) \
ccopytor_decl(ctype)

#define ccopytor_default_impl(ctype)\
ccopytor_default_decl(ctype) { \
	throw_if_null(_this); \
	throw_if_null(ptr);   \
	memcpy(_this, ptr, sizeof(ctype));\
	return success;       \
}

typedef cresult(*chashtor)(void* _this, size_t* out);

#define chashtor_decl(ctype) \
cresult ctype##_hashtor(void* _this, size_t* out)

#define chashtor_default_decl(ctype) \
chashtor_decl(ctype)

#define chashtor_default_impl(ctype) \
chashtor_default_decl(ctype) { \
	throw_if_null(_this); \
	throw_if_null(out); \
	\
	(*out) = 0U; \
	char* bytes = (char*)_this; \
	for (size_t i = 0U; i < sizeof(ctype); i++) \
		(*out) += bytes[i];\
	\
	return success;\
}

typedef cresult(*cconstructor)(void* _this);

#define cconstructor_decl(ctype) \
cresult ctype_##constructor

#define cconstructor_default_decl(ctype) \
cconstructor_decl(ctype)(void* _this)

#define cconstructor_default_impl(ctype) \
cconstructor_default_decl(ctype) { \
	throw_if_null(_this); \
	memset(_this, 0, sizeof(ctype)); \
	return success; \
}

typedef struct cbasetable {
#define cbasetable_members		\
	cconstructor constructor;	\
	cdestructor destructor;		\
	ccopytor copytor;			\
	chashtor hashtor;

	cbasetable_members;
} cbasetable;

