#ifndef STRUTIL_H
#define STRUTIL_H

extern int strutil_contains(char*, char*);
extern int strutil_ends_with(char*, char*);
extern int strutil_starts_with(char*, char*);
extern size_t strutil_index_of(char*, char);
extern size_t *strutil_indices_of(char*, char, size_t*);
extern char *strutil_lcs(char*, char*);
extern void strutil_lowercase(char*);
extern char *strutil_remove_each(char*, char*);
extern void strutil_replace_all(char*, char, char);
extern void strutil_reverse(char*);
extern char **strutil_split(char*, char*, size_t*);
extern char *strutil_substring(char*, size_t, size_t);
extern char *strutil_trim(char*);
extern void strutil_uppercase(char*);

#endif
