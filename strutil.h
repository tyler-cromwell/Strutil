#ifndef STRUTIL_H_
#define STRUTIL_H_

#include <data-structs/vector.h>

int indexOf(const char* string, const char character);
int* indexesOf(char* string, char character, int* amount);
void replaceAll(char* string, char old, char new);
Vector vect_split(char* string, const char* token);
char** split_string(char* string, char* delimiter, int* tokenAmount);
char* substring(char* str, int start, int end);
char* trim(char* original);

#endif
