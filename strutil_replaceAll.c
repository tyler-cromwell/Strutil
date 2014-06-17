/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "strutil.h"

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char* string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 */
void strutil_replaceAll(char* string, char old, char new) {
	#ifdef STRUTIL_DEBUG
		char originalp[strlen(string)+1];
		strncpy(original, string, strlen(string)+1);
		printf(COLOR_YELLOW "STRUTIL: REPLACE_ALL: Replacing all occurences of \'%c\' with \'%c\' in \"%s\"\n" COLOR_RESET, old, new, string);
	#endif
	size_t amount = 0;
	int* indexes = strutil_indexesOf(string, old, &amount);
	for (size_t i = 0; i < amount; i++)
		string[indexes[i]] = new;
	free(indexes);
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REPLACE_ALL: \"%s\" is now \"%s\"\n" COLOR_RESET, originial, string);
	#endif
}
