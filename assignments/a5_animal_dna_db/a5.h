#ifndef A5_H
#define A5_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DNARecord{
    char id[10];
    char classification[50];
    char *sequence;
};

struct DNARecord *load_database(const char *filename, int *record_count);
char *find_longest_sequence(struct DNARecord *database, int record_count, int *longest_length);
int count_by_classification(struct DNARecord *database, int record_count, const char *classification);
double calculate_average_sequence_length(struct DNARecord *database, int record_count);
void free_database(struct DNARecord *database, int record_count);
int add_record(struct DNARecord **db_ptr, int *record_count, const char *id, const char *classification, const char *sequence);
int delete_record(struct DNARecord **db_ptr, int *record_count, const char *id_to_delete);

#endif // A5_H
