#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "a5.h"

#define MAX_DNA_LENGTH 5096

/**
 * Function Name: null_terminate_helper
 * Purpose: This helper function NULL terminates a string.
 * 
 * Parameter(s):
 *  str: Pointer to the string that should be null-terminated.
 *  size: The total size of the string.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Modifies the current string by adding a null terminator at the final index.
 */

void null_terminate_helper(char *str, int size) {
    str[size - 1] = '\0';
}

/**
 * Function Name: load_database
 * Purpose: This function loads the animal information into a struct array.
 * 
 * Parameter(s):
 *  filename: Pointer to a char that contains the name of the file.
 *  record_count: Pointer to the total record count.
 * 
 * Return Value(s):
 *  Returns the memory address of the struct containing that animal's information.
 *  Returns NULL if the file doesn't open or if the database fails to exist.
 * 
 * Side Effect(s):
 *  Print an error if the file does not open or exist.
 *  Print an error if the memory allocation does not work.
 *  Update the pointer keeping track of the total records.
 */

struct DNARecord *load_database(const char *filename, int *record_count) {
    FILE *fp = fopen(filename, "r");

    // Check if the file exists and is working
    if(fp == NULL) {
        printf("Error accessing: %s\n", filename);
        return NULL;
    }

    char line[MAX_DNA_LENGTH + 100];

    // Loop to find the total amount of animals in the database
    while(fgets(line, sizeof(line), fp) != NULL) {
        (*record_count)++;
    }

    // Check there are records available
    if(*record_count == 0) {
        printf("There are no records to load into the database.\n");
        fclose(fp);
        return NULL;
    }

    // Rewind file back to the top
    rewind(fp);

    // Allocate memory for the database
    struct DNARecord *database = malloc(*record_count * sizeof(struct DNARecord));

    // Check if the database exists
    if(database == NULL){
        printf("Memory allocation failed.\n");
        fclose(fp);
        return NULL;
    }

    // Loop through database creating an array index in the database for each animal
    int valid_records = 0;

    while(fgets(line, sizeof(line), fp) != NULL) {
        // Get each value from the CSV file by tokenizing the elements with a comma as a delimiter
        char *id_token = strtok(line, ",");
        char *classification_token = strtok(NULL, ",");
        char *sequence_token = strtok(NULL, "\n");

        // Make sure none of the fields are empty
        if(id_token == NULL || classification_token == NULL || sequence_token == NULL) {
            continue;
        }

        size_t seq_len = strlen(sequence_token);

        // Loop through the sequence token removing any whitespace or newline from the end of the sequence
        while(seq_len > 0 && (sequence_token[seq_len - 1] == '\n' || sequence_token[seq_len - 1] == ' ')) {
            sequence_token[seq_len - 1] = '\0';
            seq_len--;
        }

        // Populate the value fields for the animal structure
        strncpy(database[valid_records].id, id_token, sizeof(database[valid_records].id) - 1);
        null_terminate_helper(database[valid_records].id, sizeof(database[valid_records].id));

        strncpy(database[valid_records].classification, classification_token, sizeof(database[valid_records].classification) - 1);
        null_terminate_helper(database[valid_records].classification, sizeof(database[valid_records].classification));

        // Allocate memory for the sequence part of the animal classification
        database[valid_records].sequence = malloc((strlen(sequence_token) + 1) * sizeof(char));
        
        // Make sure the memory allocation for the sequence works
        if(database[valid_records].sequence != NULL) {
            strcpy(database[valid_records].sequence, sequence_token);
            valid_records++;
        }
        else{
            printf("Memory allocation for the sequence failed.\n");

            // Free previously allocated sequences
            for(int j = 0; j < valid_records; j++) {
                free(database[j].sequence);
                database[j].sequence = NULL;
            }
            
            *record_count = 0;

            free(database);
            fclose(fp);
            return NULL;
        }
    }

    // Make sure there is at least one valid record
    if(valid_records == 0) {
        printf("No valid records in database.\n");
        free(database);
        fclose(fp);
        return NULL;
    }

    // Update record_count to reflect actual valid records
    *record_count = valid_records;

    fclose(fp);
    return database;
}

/**
 * Function Name: find_longest_sequence
 * Purpose: This function finds the longest DNA sequence in the database.
 * 
 * Parameter(s):
 *  database: A pointer to the database array.
 *  record_count: The number of records in the database.
 *  longest_length: A pointer to the longest length size.
 * 
 * Return Value(s):
 *  Returns NULL if the database doesn't exist, the record count is 0, or the longest length is NULL.
 *  Return the ID of the record with the longest sequence length.
 * 
 * Side Effect(s):
 *  Modifies the longest length pointer to 0 initially and then to the length of the largest sequence.
 */

char *find_longest_sequence(struct DNARecord *database, int record_count, int *longest_length) {
    
    // Check if the database exists, the record count is greater than 0, and the longest length is not NULL
    if(database == NULL || record_count == 0 || longest_length == NULL) {
        return NULL;
    }

    // Initialize longest length to be 0 to prevent garbage being left in the value
    *longest_length = 0;
    int longest_index = 0;

    // Loop through the database checking each length of each sequence
    for(int i = 0; i < record_count; i++) {
        size_t current_length = strlen(database[i].sequence);

        // Check if the current length is longer than the longest length we have
        if(current_length > *longest_length) {
            *longest_length = current_length;
            longest_index = i;
        }
    }

    return database[longest_index].id;
}

/**
 * Function Name: count_by_classification
 * Purpose: This function takes in a classification to search for and returns the number of occurrences of that classification.
 * 
 * Parameter(s):
 *  database: A pointer to the database.
 *  record_count: The number of records in the database.
 *  classification: The classification string to search for.
 * 
 * Return Value(s):
 *  Returns the total count of the specific classification.
 *  Returns 0 if the database doesn't exist or the record count equals 0.
 * 
 * Side Effect(s):
 *  None.
 */

int count_by_classification(struct DNARecord *database, int record_count, const char *classification) {
    int total_class_count = 0;

    // Check if the database exists and that there are records available
    if(database == NULL || record_count == 0) {
        return total_class_count;
    }

    // Loop through the database checking if the searched classification equals the database's classification
    for(int i = 0; i < record_count; i++) {
        if(strcmp(classification, database[i].classification) == 0) {
            total_class_count++;
        }
    }

    return total_class_count;
}

/**
 * Function Name: calculate_average_sequence_length
 * Purpose: This function calculates the average length of the sequences found in the database.
 * 
 * Parameter(s):
 *  database: A pointer to the database.
 *  record_count: The number of records in the database.
 * 
 * Return Value(s):
 *  Returns the average sequence length as a double.
 *  Returns 0 if the data base doesn't exist or there are no available records.
 * 
 * Side Effect(s):
 *  None.
 */

double calculate_average_sequence_length(struct DNARecord *database, int record_count) {
    double avg_sequence_len = 0.0;
    double total = 0.0;
    
    // Check if the database exists and that there are records available
    if(database == NULL || record_count == 0) {
        return avg_sequence_len;
    }

    // Loop through the database adding the length of each sequence string to the total
    for(int i = 0; i < record_count; i++) {
        total += strlen(database[i].sequence);
    }

    // Calculate the average sequence length
    avg_sequence_len = total / record_count;

    return avg_sequence_len;
}

/**
 * Function Name: add_record
 * Purpose: This function adds a new record to database.
 * 
 * Parameter(s):
 *  db_ptr: A pointer to the database pointer.
 *  record_count: A pointer to the total record count.
 *  id: A string storing the new ID value.
 *  classification: A string storing the new classification value.
 *  sequence: A string storing the new classification value.
 * 
 * Return Value(s):
 *  Returns the value of 1 if the record was successfully added to the database.
 *  Returns the value of 0 if the record failed to be added to the database.
 * 
 * Side Effect(s):
 *  Print the reallocation of memory failed.
 *  Modify the database pointer if the reallocation is successful.
 *  Modifies the record count pointer if the record is successfully added.
 *  Print the allocation of memory for the sequence failed.
 */

int add_record(struct DNARecord **db_ptr, int *record_count, const char *id, const char *classification, const char *sequence) {
    // Create a temporary database to store the reallocated memory for a new animal
    struct DNARecord *temp_db = realloc(*db_ptr, (*record_count + 1) * sizeof(struct DNARecord));

    // Check if the reallocation failed
    if(temp_db == NULL) {
        printf("Reallocation of memory failed.\n");
        return 0;
    }

    // Update the database pointer with the reallocated temporary database
    *db_ptr = temp_db;

    *record_count += 1;

    // Add the ID to the database in the last record position
    strncpy((*db_ptr)[*record_count - 1].id, id, sizeof((*db_ptr)[*record_count - 1].id));
    null_terminate_helper((*db_ptr)[*record_count - 1].id, sizeof((*db_ptr)[*record_count - 1].id));

    // Add the classification to the database in the last record position
    strncpy((*db_ptr)[*record_count - 1].classification, classification, sizeof((*db_ptr)[*record_count - 1].classification));
    null_terminate_helper((*db_ptr)[*record_count - 1].classification, sizeof((*db_ptr)[*record_count - 1].classification));

    // Dynamically allocate the sequence
    (*db_ptr)[*record_count - 1].sequence = malloc((strlen(sequence) + 1) * sizeof(char));

    // Check if the sequence is not NULL
    if((*db_ptr)[*record_count - 1].sequence != NULL) {
        strcpy((*db_ptr)[*record_count - 1].sequence, sequence);
    }
    else {
        printf("Error allocating memory for the sequence.\n");
        *record_count -= 1;
        return 0;
    }

    return 1;
}

/**
 * Function Name: delete_record
 * Purpose: This function deletes a record from the database.
 * 
 * Parameter(s):
 *  db_ptr: A pointer to the database pointer.
 *  record_count: A pointer to the total record count.
 *  id_to_delete: A string to the ID to delete.
 * 
 * Return Value(s):
 *  Returns the value of 1 if the record was successfully deleted.
 *  Returns the value of 0 if there was an error deleting the record.
 * 
 * Side Effect(s):
 *  Prints an error message if there are no records available to delete.
 *  Prints an error message if the ID to delete could not be found in the database.
 *  Frees memory connected to the deleted record.
 *  Shifts the modified database to be one less element.
 */

int delete_record(struct DNARecord **db_ptr, int *record_count, const char *id_to_delete) {
    // Check if there are records available
    if(*record_count == 0 || *db_ptr == NULL) {
        printf("Error: there are no available records.\n");
        return 0;
    }

    int index_to_delete = -1;

    // Loop to find the record to delete by its ID
    for(int i = 0; i < *record_count; i++) {
        // Use string compare to find if the ID to delete exists
        if(strcmp(((*db_ptr)[i].id), id_to_delete) == 0) {
            index_to_delete = i;
            break;
        }
    }

    // Check if the index to delete value changed, and if it didn't, the ID searched for doesn't exist
    if(index_to_delete == -1) {
        printf("Record with ID: %s could not be found.\n", id_to_delete);
        return 0;
    }

    // Free the sequence memory from the record
    free((*db_ptr)[index_to_delete].sequence);
    (*db_ptr)[index_to_delete].sequence = NULL;
    
    // Shift all remaining records left to fill the deleted records position
    for (int i = index_to_delete; i < *record_count - 1; i++) {
        (*db_ptr)[i] = (*db_ptr)[i + 1];
    }

    *record_count -= 1;

    if(*record_count == 0) {
        free(*db_ptr);
        *db_ptr = NULL;
        return 1;
    }

    // Create a temporary database using realloc with the new size of record count
    struct DNARecord *temp_db = realloc(*db_ptr, (*record_count) * sizeof(struct DNARecord));

    // Check if the reallocation worked and set the temporary database to equal the main database
    if (temp_db != NULL) {
        *db_ptr = temp_db;
    }

    return 1;
}

/**
 * Function Name: free_database
 * Purpose: This function frees all memory that was allocated in the previous steps.
 * 
 * Parameter(s):
 *  database: A pointer to the database.
 *  record_count: The number of records in the database.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Print an error message if the database doesn't exist or there are no records available.
 */

void free_database(struct DNARecord *database, int record_count) {
    // Check if the database exists
    if(database == NULL) {
        return;
    }

    // Loop through the database freeing the memory allocated to it
    for(int i = 0; i < record_count; i++) {
        if(database[i].sequence != NULL) {
            // Free the memory allocated to each sequence in the array
            free(database[i].sequence);
            database[i].sequence = NULL;
        }
    }

    // Free the memory of the database
    free(database);
}