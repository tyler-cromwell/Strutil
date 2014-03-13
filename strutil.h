#ifndef STRUTIL_H_
#define STRUTIL_H_

extern int strutil_contains(char* string, char* sequence);
extern int strutil_endsWith(char* string, char* endtok);
extern int strutil_startsWith(char* string, char* starttok);
extern int strutil_indexOf(const char* string, const char character);
extern int* strutil_indexesOf(char* string, char character, unsigned int* amount);
extern char* strutil_removeThese(char* string, char* chars);
extern void strutil_replaceAll(char* string, char old, char new);
extern char** strutil_split(char* string, const char* delimiter, unsigned int* tokenAmount);
extern char* strutil_substring(char* str, int start, int end);
extern char* strutil_trim(char* original);

#endif
