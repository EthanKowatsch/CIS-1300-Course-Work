#include <stdbool.h>
#include "a4.h"

/**
 * Function Name: get_string_length
 * Purpose: This function gets the length of an inputted string.
 * 
 * Parameter(s):
 *  sequence: A string literal storing a DNA sequence string.
 * 
 * Return Value(s):
 *  Returns the length of the string as an integer.
 * 
 * Side Effects:
 *  None.
 */

int get_string_length(const char *sequence) {
    // Declare integer to store the length of the string
    int length = 0;
    
    // Loop through the string until you reach the NULL terminator and increment the length variable
    while(sequence[length] != '\0') {
        length++;
    }

    return length;
}

/**
 * Function Name: calculate_gc_content
 * Purpose: This function counts the total Guanine (G) and Cytosine (C) bases in the DNA sequence.
 * 
 * Parameter(s):
 *  dna_sequence: A string literal containing a DNA sequence string.
 * 
 * Return Value(s):
 *  Returns the Guanine (G) and Cytosine (C) bases in the form of a percentage of the DNA sequence.
 * 
 * Side Effects:
 *  None.
 */

float calculate_gc_content(const char *dna_sequence) {
    // Get the length of the DNA sequence string
    int total_sequence_length = get_string_length(dna_sequence);

    // Declare variable to store the total Guanine (G) and Cytosine (C) bases count
    float total_gc_content = 0.0f;

    // Make sure string is not empty
    if(total_sequence_length == 0) {
        return total_gc_content;
    }

    // Declare variables to store the total counts of Guanine (G) and Cytosine (C) bases
    int G_count = 0, C_count = 0;

    // Iterate through the DNA sequence string until the end counting all the Guanine (G) and Cytosine (C) bases
    for(int i = 0; i < total_sequence_length; i++) {
        // If statement to determine if either base is in the current index of the character array
        if(dna_sequence[i] == 'G') {
            // Increment the total Guanine (G) count
            G_count++;
        }
        else if(dna_sequence[i] == 'C') {
            // Increment the total Cytosine (C) count
            C_count++;
        }
    }

    // Calculate the total Guanine (G) and Cytosine (C) bases content
    total_gc_content = ((G_count + C_count) * 100.0f) / total_sequence_length;

    return total_gc_content;
}

/**
 * Function Name: find_motif
 * Purpose: This function finds the first index the genetic motif (recurring pattern) appears in the DNA sequence.
 * 
 * Parameter(s):
 *  dna_sequence: A string literal containing a DNA sequence string.
 *  motif: A string literal containing the genetic motif to search for in the DNA sequence.
 * 
 * Return Value(s):
 *  Returns the index the genetic motif first appears at, or -1 if the genetic motif doesn't exist in the DNA sequence.
 * 
 * Side Effects:
 *  None.
 */

int find_motif(const char *dna_sequence, const char *motif) {
    // Get the length of the DNA sequence string
    int total_sequence_length = get_string_length(dna_sequence);

    // Get the length for the motif string sequence
    int total_motif_length = get_string_length(motif);

    // Check if the motif has a value, check the length of the sequence and make sure the motif's length is not greater than that total sequence length
    if(total_motif_length == 0 || total_sequence_length == 0 || total_motif_length > total_sequence_length) {
        return -1;
    }

    // Calculate the last possible index the motif could start preventing the loop from searching for the motif past this point
    int last_possible_index = total_sequence_length - total_motif_length;

    // Loop through the DNA sequence array
    for(int i = 0; i <= last_possible_index; i++) {
        // Declare boolean for if the motif is within the sequence (1 meaning true, 0 being false)
        bool genetic_motif_matched = true;

        // Check each character in the motif with the current DNA sequence segment
        for(int j = 0; j < total_motif_length; j++) {
            // If the DNA sequence character does not equal the remaining motif characters, break out of this loop and try again
            if(dna_sequence[i + j] != motif[j]) {
                // Update the boolean variable storing if the genetic motif matched to be false
                genetic_motif_matched = false;
                break;
            }
        }

        // Check if there is a match of the motif within the DNA sequence
        if(genetic_motif_matched) {
            // Return the index that i is at as that is the start of the motif
            return i;
        }
    }
    
    return -1;
}

/**
 * Function Name: calculate_genetic_difference
 * Purpose: This function calculates the genetic difference (Hamming Distance) between two DNA sequence strings.
 * 
 * Parameter(s):
 *  seq1: A string literal representing the first DNA sequence.
 *  seq2: A string literal representing the second DNA sequence.
 * 
 * Return Value(s):
 *  Returns the total Hamming distance between the two DNA sequence strings or -1 indicating an error with one of the string sequences.
 * 
 * Side Effects:
 *  None.
 */

int calculate_genetic_difference(const char *seq1, const char *seq2) {
    // Declare integers to store the length of each DNA sequence string
    int seq1_length = get_string_length(seq1);
    int seq2_length = get_string_length(seq2);

    // Declare integer variable to store the Hamming distance total
    int hamming_distance_count = 0;
    
    // Check if the DNA sequences are different lengths and return false if they're
    if(seq1_length != seq2_length) {
        return -1;
    }

    // Loop through function totalling up the Hamming distance amount
    for(int i = 0; i < seq1_length; i++) {
        // If the sequence indexes don't equal each other, add to the Hamming distance count
        if(seq1[i] != seq2[i]) {
            hamming_distance_count++;
        }
    }
    
    return hamming_distance_count;
}

/**
 * Function Name: is_palindrome
 * Purpose: This function determines if the DNA string sequence is a palindrome (reads the same forwards as backwards).
 * 
 * Parameter(s):
 *  dna_sequence: A pointer to a DNA sequence string.
 * 
 * Return Value(s):
 *  Returns 1 (true) if the DNA string sequence is a palindrome and 0 (false) if the DNA string sequence is not a palindrome.
 * 
 * Side Effects:
 *  None.
 */

int is_palindrome(const char *dna_sequence) {
    // Get the length of the dna_sequence string
    int total_length = get_string_length(dna_sequence);
    
    // Check if the dna_sequence string is empty, this is a palindrome as well
    if(total_length == 0) {
        return 1;
    }

    // Save variable storing the end index of the string
    int last_index = total_length - 1;

    // Store value for the middle of the string to prevent looping through the whole array
    int middle_index = total_length / 2;

    // Loop the dna_sequence string stopping if the character being checked isn't the same
    for(int i = 0; i < middle_index; i++) {
        // Check if the character in the DNA string sequence doesn't equal each other, return false
        if(dna_sequence[i] != dna_sequence[last_index]) {
            return 0;
        }

        // Decrement the last index value working backwards through the string
        last_index--;
    }

    return 1;
}

/**
 * Function Name: are_anagrams
 * Purpose: This function determines whether the DNA sequence strings are anagrams of each other (whether the strings have the matching number of nucleotides).
 * 
 * Parameter(s):
 *  seq1: A string literal representing the first DNA sequence.
 *  seq2: A string literal representing the second DNA sequence.
 * 
 * Return Value(s):
 *  Returns 1 (true) if the conditions are met for the DNA sequences to be anagrams, and 0 (false) otherwise.
 * 
 * Side Effects:
 *  None.
 */

int are_anagrams(const char *seq1, const char *seq2) {
    // Declare integers to store the length of each DNA sequence string
    int seq1_length = get_string_length(seq1);
    int seq2_length = get_string_length(seq2);
    
    // Check if the DNA sequences are different lengths and return false if they're
    if(seq1_length != seq2_length) {
        return 0;
    }

    /**
     * A = Index 0
     * C = Index 1
     * G = Index 2
     * T = Index 3
     */

    // Declare array storing the count of each nucleotide, setting each value to 0 for each sequence array
    int nucleotide_frequency_seq1[] = {0, 0, 0, 0};
    int nucleotide_frequency_seq2[] = {0, 0, 0, 0};

    // Declare integer variable to store the length of the frequency arrays
    int frequency_array_length = sizeof(nucleotide_frequency_seq1) / sizeof(nucleotide_frequency_seq1[0]);

    // Loop over the first DNA sequence char array counting the different nucleotides
    for(int i = 0; i < seq1_length; i++) {
        // Add count for each letter that appears
        if(seq1[i] == 'A') {
            // Add to the Adenine (A) total
            nucleotide_frequency_seq1[0]++;
        }
        else if(seq1[i] == 'C') {
            // Add to the Cytosine (C) total
            nucleotide_frequency_seq1[1]++;
        }
        else if(seq1[i] == 'G') {
            // Add to the Guanine (G) total
            nucleotide_frequency_seq1[2]++;
        }
        else if(seq1[i] == 'T') {
            // Add to the Thymine (T) total
            nucleotide_frequency_seq1[3]++;
        }
        else {
            // Return false as there is a false input
            return 0;
        }
    }

    // Loop over the second DNA sequence char array counting the different nucleotides
    for(int i = 0; i < seq2_length; i++) {
        // Add count for each letter that appears
        if(seq2[i] == 'A') {
            // Add to the Adenine (A) total
            nucleotide_frequency_seq2[0]++;
        }
        else if(seq2[i] == 'C') {
            // Add to the Cytosine (C) total
            nucleotide_frequency_seq2[1]++;
        }
        else if(seq2[i] == 'G') {
            // Add to the Guanine (G) total
            nucleotide_frequency_seq2[2]++;
        }
        else if(seq2[i] == 'T') {
            // Add to the Thymine (T) total
            nucleotide_frequency_seq2[3]++;
        }
        else {
            // Return false as there is a false input
            return 0;
        }
    }

    // Loop through both frequency arrays to determine if the nucleotide counts are the same
    for(int i = 0; i < frequency_array_length; i++) {
        // If one of the indexes are not the same, return 0
        if(nucleotide_frequency_seq1[i] != nucleotide_frequency_seq2[i]) {
            return 0;
        } 
    }
    
    return 1;
}