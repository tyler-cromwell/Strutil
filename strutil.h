#ifndef STRUTIL_H_
#define STRUTIL_H_

#include "data-structs/vector.h"

extern int indexOf(const char* string, const char character);
extern int* indexesOf(char* string, char character, int* amount);
extern void replaceAll(char* string, char old, char new);
extern Vector vect_split(char* string, const char* token);
extern char** split_string(char* string, char* delimiter, int* tokenAmount);
extern char* substring(char* str, int start, int end);
extern char* trim(char* original);

#endif
