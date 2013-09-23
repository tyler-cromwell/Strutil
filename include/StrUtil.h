#ifndef STRUTIL_H_
#define STRUTIL_H_

#include <CVector.h>
/*
 * Last Updated: Monday, August 26th 2013
 */
int indexOf(const char* string, const char character);
CVector split(char* str, const char* delim);
char* substr(char* str, int start, int end);

#endif
