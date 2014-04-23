/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Compares the last n bytes of string to endtok to
 * see if string ends with endtok.
 * Argument(s):
 *   char* string: The string being searched.
 *   char* endtok: The token being searched for.
 * Returns: an integer (1 for yes, 0 for no).
 */
int strutil_endsWith(char* string, char* endtok) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: ENDS_WITH: Comparing the last \'%d\' bytes of \"%s\" to \"%s\"\n" COLOR_RESET, strlen(endtok), string, endtok);
	#endif
	char* substr = strutil_substring(string, strlen(string)-strlen(endtok), strlen(string));
	int bit = 0;
	if (!strncmp(substr, endtok, strlen(endtok)))
		bit = 1;
	free(substr);
	return bit;
}
