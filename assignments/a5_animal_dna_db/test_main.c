#include <stdio.h>
#include <string.h>
#include "a5.h"

int main(void) {
    struct DNARecord *database = NULL;
    int record_count = 0;

    const char *db_filename = "dna_db.csv";

    printf("=== Assignment 5: Function Tests ===\n\n");

    /* -----------------------------------
       Load database
       ----------------------------------- */
    printf("Loading database from '%s'...\n", db_filename);

    database = load_database(db_filename, &record_count);

    if (!database || record_count == 0) {
        printf("Database load failed or file was empty.\n");
        return 1;
    }

    printf("Loaded %d records.\n\n", record_count);

    /* -----------------------------------
       Find longest sequence
       ----------------------------------- */
    printf("[find_longest_sequence]\n");
    int longest_length = 0;
    char *longest_id = find_longest_sequence(database, record_count, &longest_length);

    if (longest_id) {
        printf("Longest sequence belongs to: %s (Length: %d)\n\n",
               longest_id, longest_length);
    }

    /* -----------------------------------
       Count by classification
       ----------------------------------- */
    printf("[count_by_classification]\n");
    const char *query_class_1 = "Mammal";
    const char *query_class_2 = "Reptile";

    printf("Count '%s': %d\n", query_class_1,
           count_by_classification(database, record_count, query_class_1));

    printf("Count '%s': %d\n\n", query_class_2,
           count_by_classification(database, record_count, query_class_2));

    /* -----------------------------------
       Average sequence length
       ----------------------------------- */
    printf("[calculate_average_sequence_length]\n");
    double avg_len = calculate_average_sequence_length(database, record_count);
    printf("Average sequence length: %.2f\n\n", avg_len);

    /* -----------------------------------
       Add a new record
       ----------------------------------- */
    printf("[add_record]\n");

    const char *new_id     = "ID999";
    const char *new_class  = "Avian";
    const char *new_seq    = "TAGATAGATAGATAG";

    printf("Adding new record: %s\n", new_id);

    if (add_record(&database, &record_count, new_id, new_class, new_seq)) {
        printf("Record added successfully. Total records: %d\n", record_count);
    } else {
        printf("Failed to add record.\n");
    }

    printf("\n");

    /* -----------------------------------
       Delete records
       ----------------------------------- */
    printf("[delete_record]\n");

    const char *del_id_existing = "ID002";
    const char *del_id_missing  = "ID-XYZ";

    printf("Deleting record: %s\n", del_id_existing);

    if (delete_record(&database, &record_count, del_id_existing)) {
        printf("Record deleted. Count is now %d.\n", record_count);
    } else {
        printf("Record '%s' not found.\n", del_id_existing);
    }

    printf("\nDeleting non-existent record: %s\n", del_id_missing);

    if (!delete_record(&database, &record_count, del_id_missing)) {
        printf("Record '%s' not found, as expected.\n", del_id_missing);
    } else {
        printf("Unexpected deletion of non-existent record.\n");
    }

    printf("\n");

    /* -----------------------------------
       Free memory
       ----------------------------------- */
    printf("[free_database]\n");
    printf("Cleaning up %d records...\n", record_count);

    free_database(database, record_count);

    printf("Cleanup complete.\n");

    return 0;
}