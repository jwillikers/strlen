#pragma once
#include <strlen/export.h>

// Convert a string to an integer.
// Zero is returned if a null pointer is passed in or a conversion can not be
// performed.
#ifdef __cplusplus
extern "C" STRLEN_EXPORT int my_strlen(char const *c);
#else
STRLEN_EXPORT int my_strlen(char const *c);
#endif
