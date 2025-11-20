#include <stdio.h>
#include <math.h>
#include "a4.h"

#define THRESHOLD 0.001f

int main(void) {
    printf("=== Assignment 4: Function Tests ===\n\n");

    /* -----------------------------------
       Test: calculate_gc_content
       ----------------------------------- */
    printf("[calculate_gc_content]\n");
    const char *gc_tests[] = {
        "GATAG",
        "GATTAG",
        "GATAC",
        "ACTAG",
        ""
    };

    for (int i = 0; i < 5; i++) {
        printf("Sequence: %-10s -> GC Content: %.3f%%\n",
               gc_tests[i],
               calculate_gc_content(gc_tests[i]));
    }
    printf("\n");

    /* -----------------------------------
       Test: find_motif
       ----------------------------------- */
    printf("[find_motif]\n");
    printf("find_motif(\"GATAG\", \"TAG\")  -> %d\n", find_motif("GATAG", "TAG"));
    printf("find_motif(\"TAG\", \"GATAG\")  -> %d\n", find_motif("TAG", "GATAG"));
    printf("find_motif(\"C\", \"\")         -> %d\n", find_motif("C", ""));
    printf("find_motif(\"GATAG\", \"GATAG\") -> %d\n", find_motif("GATAG", "GATAG"));
    printf("\n");

    /* -----------------------------------
       Test: calculate_genetic_difference
       ----------------------------------- */
    printf("[calculate_genetic_difference]\n");
    printf("difference(\"GATAG\", \"AGAGT\")  -> %d\n",
           calculate_genetic_difference("GATAG", "AGAGT"));
    printf("difference(\"GAGCCT\", \"AAGCTT\") -> %d\n",
           calculate_genetic_difference("GAGCCT", "AAGCTT"));
    printf("difference(\"\", \"\")            -> %d\n",
           calculate_genetic_difference("", ""));
    printf("\n");

    /* -----------------------------------
       Test: is_palindrome
       ----------------------------------- */
    printf("[is_palindrome]\n");
    const char *pal_tests[] = {
        "GATAG",
        "GATTAG",
        "GAGCCT",
        "A",
        ""
    };

    for (int i = 0; i < 5; i++) {
        printf("Sequence: %-10s -> Palindrome? %s\n",
               pal_tests[i],
               is_palindrome(pal_tests[i]) ? "Yes" : "No");
    }
    printf("\n");

    /* -----------------------------------
       Test: are_anagrams
       ----------------------------------- */
    printf("[are_anagrams]\n");
    printf("anagram(\"GATAG\", \"AGAGT\")  -> %s\n",
           are_anagrams("GATAG", "AGAGT") ? "Yes" : "No");
    printf("anagram(\"GAGCCT\", \"AAGCTT\") -> %s\n",
           are_anagrams("GAGCCT", "AAGCTT") ? "Yes" : "No");
    printf("anagram(\"\", \"\")            -> %s\n",
           are_anagrams("", "") ? "Yes" : "No");
    printf("\n");

    return 0;
}