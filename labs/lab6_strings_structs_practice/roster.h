#ifndef ROSTER_H
#define ROSTER_H

#define MAX_CLASS_SIZE 20
#define MAX_NAME_SIZE 50
#define MAX_BUFFER_SIZE 50

struct student {
    char first_name[MAX_NAME_SIZE];
    char last_name[MAX_NAME_SIZE];
    int student_id;
    double grade;
};

void remove_newline(char name[]);
void print_menu(void);
void add_student(struct student roster[], int *num_students);
void print_roster(struct student roster[], int num_students);
void search_by_lastname(struct student roster[], int num_students);
void update_grade(struct student roster[], int num_students);
struct student* find_highest_grade(struct student roster[], int num_students);
double grade_average(struct student roster[], int num_students);

#endif