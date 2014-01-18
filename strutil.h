#ifndef STRUTIL_H_
#define STRUTIL_H_

#include "data-structs/vector.h"

extern int contains(char* string, char* sequence);
extern int indexOf(const char* string, const char character);
extern int* indexesOf(char* string, char character, int* amount);
extern char* removeThese(char* string, char* chars);
extern void replaceAll(char* string, char old, char new);
extern Vector vector_split(char* string, const char* token);
extern char** split_string(char* string, const char* delimiter, int* tokenAmount);
extern char* substring(char* str, int start, int end);
extern char* trim(char* original);

#endif
