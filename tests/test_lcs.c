#include <stdio.h>
#include <stdlib.h>

#include "strutil.h"


int main(void) {
    char *str1 = "Spanking";
    char *str2 = "Amputation";
    char *lcs = strutil_lcs(str1, str2);

    printf("Longest Common Subsequence between:\n");
    printf("\"%s\" x \"%s\" = \"%s\"\n", str1, str2, lcs);

    free(lcs);
    return 0;
}
