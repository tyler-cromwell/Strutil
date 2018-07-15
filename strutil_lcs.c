#include <stdlib.h>
#include <string.h>

#include "strutil.h"

typedef enum {
    NONE = 0,
    UP = 1,
    LEFT = 2,
    DIAGONAL = 4
} direction_t;


/*
 * Translated from pseudocode in the book:
 * "Introduction to Algorithms, 3rd Edition", pages 394-395.
 *
 * Returns: the LCS.
 * (Pointer must be freed)
 */
char * strutil_lcs(char *str1, char *str2) {
    size_t m = strlen(str1);
    size_t n = strlen(str2);
    size_t l = 0;

    char *B = calloc(m * n, sizeof(char));
    char *C = calloc(m * n, sizeof(char));
    char *lcs = NULL;

    // Populate tables with scores/directions
    for (size_t i = 1; i < m; i++) {
        for (size_t j = 1; j < n; j++) {
            if (str1[i] == str2[j]) {
                C[i*n+j] = C[(i-1)*n+(j-1)] + 1;
                B[i*n+j] = DIAGONAL;
            }
            else if (C[(i-1)*n+j] >= C[i*n+(j-1)]) {
                C[i*n+j] = C[(i-1)*n+j];
                B[i*n+j] = UP;
            }
            else {
                C[i*n+j] = C[i*n+(j-1)];
                B[i*n+j] = LEFT;
            }
        }
    }

    size_t i = m-1;
    size_t j = n-1;

    // Construct string backwards
    while (i != 0 && j != 0) {
        if (B[i*n+j] == DIAGONAL) {
            i--;
            j--;
            lcs = realloc(lcs, (l+1) * sizeof(char));
            lcs[l++] = str1[i+1];
        }
        else if (B[i*n+j] == UP) {
            i--;
        }
        else {
            j--;
        }
    }

    // Add null
    lcs = realloc(lcs, (l+1) * sizeof(char));
    lcs[l] = '\0';

    // Reverse so it's readable
    char *result = strutil_reverse(lcs);

    free(B);
    free(C);
    free(lcs);
    return result;
}
