#ifndef STRUTIL_H_
#define STRUTIL_H_

#include <CVector.h>

int indexOf(const char* string, const char character);
int* indexesOf(char* string, char character, int* amount);
void replaceAll(char* string, char old, char new);
CVector split(char* str, const char* token);
char* substr(char* str, int start, int end);
char* trim(char* original);

#endif