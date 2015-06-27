#ifndef STRUTIL_H
#define STRUTIL_H

#ifdef STRUTIL_DEBUG
    #ifndef COLOR_YELLOW
        #define COLOR_YELLOW "\x1b[33m" // ANSI Escape Code for turning on yellow terminal text
    #endif
    #ifndef COLOR_RESET
        #define COLOR_RESET "\x1b[0m" // ANSI Escape Code for turning off colored terminal text
    #endif
#endif

#ifndef ASCII_SPACE
    #define ASCII_SPACE 32 // The ASCII value for the Space character.
#endif

#ifndef ASCII_NULL
    #define ASCII_NULL 0 // The ASCII value for the Null character.
#endif

extern int strutil_contains(char*, char*);
extern int strutil_endsWith(char*, char*);
extern int strutil_startsWith(char*, char*);
extern size_t strutil_indexOf(char*, char);
extern size_t *strutil_indexesOf(char*, char, size_t*);
extern char *strutil_lowercase(char*);
extern char *strutil_removeThese(char*, char*);
extern void strutil_replaceAll(char*, char, char);
extern char **strutil_split(char*, char*, size_t*);
extern char *strutil_substring(char*, size_t, size_t);
extern char *strutil_trim(char*);
extern char *strutil_uppercase(char*);

#endif
