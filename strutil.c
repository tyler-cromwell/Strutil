/* Standard: gnu99 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data-structs/vector.h"
#include "strutil/strutil.h"

#ifdef STRUTIL_DEBUG
	#define COLOR_YELLOW "\x1b[33m" // ANSI Escape Code for turning on yellow terminal text
	#define COLOR_RESET  "\x1b[0m"  // ANSI Escape Code for turning off colored terminal text
#endif

#define SPACE 32 // The ASCII value for the Space character.
#define NUL   0  // The ASCII value for the Null character.

/*
 * Checks if a string contains another string.
 * Argument(s):
 *   char* string: the string being searched.
 *   char* sequence: the sequence to search for.
 * Returns: an integer (1 for found, 0 for not).
 */
int contains(char* string, char* sequence) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: CONTAINS: Searching \"%s\" for \"%s\"\n" COLOR_RESET, string, sequence);
	#endif
	unsigned int found = 0;
	unsigned int length = strlen(string);
	for (unsigned int i = 0; i < length; i++) {
		#ifdef STRUTIL_DEBUG
			printf(COLOR_YELLOW "STRUTIL: CONTAINS: \"%s\" \"%s\"\n" COLOR_RESET, string, sequence);
		#endif
		if (!strncmp(string, sequence, strlen(sequence))) {
			found = 1;
			break;
		} else string++;
	}
	return found;
}

/*
 * Gets the first index of a character in a string.
 * Argument(s):
 *   const char* string: the string being examined.
 *   const char character: the character whose position being searched for.
 * Returns: the index of 'character' in 'string'
 */
int indexOf(const char* string, const char character) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEX_OF: Searching \"%s\" for first occurence of \'%c\'\n" COLOR_RESET, string, character);
	#endif
	unsigned int i = 0;
	while (string[i] != character) i++;
	return i;
}

/*
 * Gets the indexes of a character in a string.
 * Argument(s):
 *   const char* string: the string being examined.
 *   const char character: the character whose position being searched for.
 *   int* amount: the size of the array of indexes
 * Memory Management:
 *   Free the returned array when done.
 * Returns: an array of all the indexes that 'character' is found at.
 */
int* indexesOf(char* string, char character, int* amount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: INDEXES_OF: Searching \"%s\" for all occurences of \'%c\'\n" COLOR_RESET, string, character);
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
 * Removes all occurences of each character in 'chars' from 'string'.
 * Argument(s):
 *   char* string: the string to be shortened.
 *   char* chars: the characters to be removed from 'string'.
 * Pre-Condition(s):
 *   strlen(chars) < strlen(string)
 * Memory Management:
 *   Free the returned string when done.
 * Returns: the shortened string.
 */
char* removeThese(char* string, char* chars) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: Attempting to remove characters \"%s\" from \"%s\"\n" COLOR_RESET, chars, string);
	#endif
	char* shortened = calloc(strlen(string) - strlen(chars) + 1, sizeof(char));
	unsigned int index = 0;
	for (unsigned int i = 0; i < strlen(string); i++) {
		for (unsigned int j = 0; j < strlen(chars); j++) {
			if (string[i] != chars[j]) {
				#ifdef STRUTIL_DEBUG
					printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: \'%c\'\n" COLOR_RESET, string[i]);
				#endif
				shortened[index] = string[i];
				index++;
			}
		}
	}
	shortened[index] = NUL;
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REMOVE_THESE: \"%s\" shortened to \"%s\"\n" COLOR_RESET, string, shortened);
	#endif
	return shortened;
}

/*
 * Replaces all the characters in a string that match the
 * given, with the new given character.
 * Argument(s):
 *   char* string: the string to be modified.
 *   char old: the character being replaced.
 *   char new: the character doing the replacing.
 */
void replaceAll(char* string, char old, char new) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: REPLACE_ALL: Replacing all occurences of \'%c\' with \'%c\' in \"%s\"\n" COLOR_RESET, old, new, string);
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
 *   char* string: the string to be split.
 *   const char* token: the token used to split 'string' at.
 * Memory Management:
 *   Free the array member from the returned pointer when done.
 * Returns: a resizeable array of tokens.
 */
Vector vector_split(char* string, const char* token) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: VECTOR_SPLIT: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, token);
	#endif
	Vector tokens = vector_init(0);
	char* part;
	part = strtok(string, token);
	for (unsigned int i = 0; part != NULL; i++) {
		vector_add(&tokens, i, part);
		part = strtok(NULL, token);
	}
	return tokens;
}

/*
 * Splits up a string at a given token.
 * Argument(s):
 *   char* string: the string to be split.
 *   char* delimiter: the token used to split 'string' at.
 *   int* tokenAmount: a pointer to the number of tokens produced.
 * Memory Management:
 *   Free the string array when done.
 * Returns: an array of tokens.
 */
char** split_string(char* string, const char* delimiter, int* tokenAmount) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SPLIT_STRING: Spliting \"%s\" at every occurence of \"%s\"\n" COLOR_RESET, string, delimiter);
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
 *   char* original: the string to derive the substring from.
 *   int start: the starting index.
 *   int end: the ending index.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the substring.
 */
char* substring(char* original, int start, int end) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Retrieving substring of \"%s\" from %d to %d\n" COLOR_RESET, original, start, end);
	#endif
	char* substring = calloc((end-start)+1, sizeof(char));
	for (unsigned int i = 0; i < (end-start); i++)
		substring[i] = original[start+i];
	substring[end-start] = NUL;
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: SUBSTRING: Substring of \"%s\" from %d to %d is \"%s\"\n" COLOR_RESET, original, start, end, substring);
	#endif
	return substring;
}

/*
 * Trims the leading and trailing whitespace from a string.
 * Argument(s):
 *   char* original: the string to be trimmed.
 * Memory Management:
 *   Free the returned pointer when done.
 * Returns: the trimmed version of 'original'.
 */
char* trim(char* original) {
	#ifdef STRUTIL_DEBUG
		printf(COLOR_YELLOW "STRUTIL: TRIM: Trimming \"%s\"\n" COLOR_RESET, original);
	#endif
	int i = 0;
	for (; original[i] == SPACE; i++);
	int start = i;
	for (i = strlen(original)-1; original[i] == SPACE; i--);
	int end = i;
	char* new = calloc(end-start+2, sizeof(char));
	for (int j = 0; j < end-start+1; j++)
		new[j] = original[j+start];
	new[end-start+1] = NUL;
	return new;
}
