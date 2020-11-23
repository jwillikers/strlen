#pragma once

// Convert a string to an integer.
// Zero is returned if a null pointer is passed in or a conversion can not be
// performed.
#ifdef __cplusplus
extern "C" int my_strlen(char const *c);
#else
int my_strlen(char const *c);
#endif
