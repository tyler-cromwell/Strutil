/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Compares the first n bytes of string to starttok to
 * see if string starts with starttok.
 * Argument(s):
 *   char* string: The string being searched.
 *   char* starttok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
inline int strutil_startsWith(char* string, char* starttok) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: STARTS_WITH: Comparing the first \'%zd\' bytes of \"%s\" to \"%s\"\n" COLOR_RESET, strlen(starttok), string, starttok);
	#endif
	return !strncmp(string, starttok, strlen(starttok));
}
