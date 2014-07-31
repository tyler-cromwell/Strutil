#ifndef STRUTIL_H
#define STRUTIL_H

#ifdef STRUTIL_DEBUG
	#ifndef COLOR_YELLOW
		#define COLOR_YELLOW "\x1b[33m" // ANSI Escape Code for turning on yellow terminal text
	#endif
	#ifndef COLOR_RESET
		#define COLOR_RESET  "\x1b[0m"  // ANSI Escape Code for turning off colored terminal text
	#endif
#endif

#ifndef ASCII_SPACE
	#define ASCII_SPACE 32 // The ASCII value for the Space character.
#endif

#ifndef ASCII_NULL
	#define ASCII_NULL  0  // The ASCII value for the Null character.
#endif

extern int strutil_contains(char* string, char* sequence);
extern int strutil_endsWith(char* string, char* endtok);
extern int strutil_startsWith(char* string, char* starttok);
extern int strutil_indexOf(const char* string, const char character);
extern int* strutil_indexesOf(char* string, char character, size_t* amount);
extern char* strutil_lowercase(char* string);
extern char* strutil_removeThese(char* string, char* chars);
extern void strutil_replaceAll(char* string, char old, char new);
extern char** strutil_split(char* string, const char* delimiter, size_t* tokenAmount);
extern char* strutil_substring(char* str, int start, int end);
extern char* strutil_trim(char* original);
extern char* strutil_uppercase(char* string);

#endif
