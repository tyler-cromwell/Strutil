/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-structs/vector.h"
#include "strutil.h"

#ifdef STRUTIL_DEBUG
	#include "colors.h"
#endif

#define BLANK_SPACE 32  // The ASCII value for the Space character.
#define STRING_END '\0' // Null terminator, marks end of a string.

/*
 * Gets the first index of a character in a string.
 * Argument(s):
 *   const char* string, the string being examined.
 *   const char character, the character whose position being searched for.
 * Returns: the index of 'character' in 'string'
 */
int indexOf(const char* string, const char character) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Searching \"%s\" for first occurence of \'%c\'\n" COLOR_RESET, string, character);
	#endif
	unsigned int i = 0;
	while (string[i] != character) i++;
	return i;
}

/*
 * Gets the indexes of a character in a string.
 * Argument(s):
 *   const char* string, the string being examined.
 *   const char character, the character whose position being searched for.
 *   int* amount, the size of the array of indexes
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: an array of all the indexes that 'character' is found at.
 */
int* indexesOf(char* string, char character, int* amount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Searching \"%s\" for all occurences of \'%c\'\n" COLOR_RESET, string, character);
	#endif
	int buff[strlen(string)];
	for (unsigned int i = 0; i < strlen(string); i++) {
		if (string[i] == character) {
			buff[*amount] = i;
			(*amount)++;
		}
	}
	int* indexes = calloc(*amount, sizeof(int));
	for (unsigned int i = 0; i < (*amount); i++)
		indexes[i] = buff[i];
	return indexes;
}

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char* string, the string to be modified.
 *   char old, the character being replaced.
 *   char new, the character doing the replacing.
 * Returns: void.
 */
void replaceAll(char* string, char old, char new) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Replacing all occurences of \'%c\' with \'%c\' in \"%s\"\n" COLOR_RESET, old, new, string);
	#endif
	int amount = 0;
	int* indexes = indexesOf(string, old, &amount);
	for (unsigned int i = 0; i < amount; i++)
		string[indexes[i]] = new;
	free(indexes);
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string, the string to be split.
 *   const char* token, the token used to split 'string' at.
 * Memory Management:
 *   Free the array member from the returned pointer when done.
 * Returns: a resizeable array of tokens.
 */
Vector vector_split(char* string, const char* token) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, token);
	#endif
	Vector tokens = vector_init(0);
	char* part;
	part = strtok(string, token);
	for (unsigned int i = 0; part != NULL; i++) {
		vector_add(&tokens, i, (GenType) part);
		part = strtok(NULL, token);
	}
	return tokens;
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string, the string to be split.
 *   char* delimiter, the token used to split 'string' at.
 *   int* tokenAmount, a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char** split_string(char* string, const char* delimiter, int* tokenAmount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, delimiter);
	#endif
	char** tokens = calloc(1, sizeof(char*));
	char* tok = strtok(string, delimiter);
	for (unsigned int i = 0; tok != NULL; i++) {
		tokens[i] = tok;
		(*tokenAmount)++;
		tok = strtok(NULL, delimiter);
		if (tok != NULL) tokens = realloc(tokens, ((*tokenAmount)+1) * sizeof(char*));
	}
	return tokens;
}

/*
 * Derives a substring from a given string. (start <= N < end)
 * Argument(s):
 *   char* original, the string to derive the substring from.
 *   int start, the starting index.
 *   int end, the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char* substring(char* original, int start, int end) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Retrieving substring of \"%s\" from %d to %d\n" COLOR_RESET, original, start, end);
	#endif
	char* substring = calloc((end-start)+1, sizeof(char));
	for (unsigned int i = 0; i < (end-start); i++)
		substring[i] = original[start+i];
	substring[end-start] = STRING_END;
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Substring of \"%s\" from %d to %d is \"%s\"\n" COLOR_RESET, original, start, end, substring);
	#endif
	return substring;
}

/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char* original, the string to be trimmed.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the trimmed version of 'original'.
 */
char* trim(char* original) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: Trimming \"%s\"\n" COLOR_RESET, original);
	#endif
	int i = 0;
	for (; original[i] == BLANK_SPACE; i++);
	int start = i;
	for (i = strlen(original)-1; original[i] == BLANK_SPACE; i--);
	int end = i;
	char* new = calloc(end-start+2, sizeof(char));
	for (int j = 0; j < end-start+1; j++)
		new[j] = original[j+start];
	new[end-start+1] = STRING_END;
	return new;
}
