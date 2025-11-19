#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "roster.h"

/**
 * Function Name: remove_newline
 * Purpose: This function removes the newline in the name.
 * 
 * Parameter(s):
 *  name: Array of chars containing a name.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Modifies the contents of the char array passed into the function with a null terminator.
 */

void remove_newline(char name[]) {
    size_t length = strlen(name);

    // Loop through the name array until the NULL terminator
    for(int i = 0; i < length; i++) {
        if(name[i] == '\n') {
            name[i] = '\0';
            break;
        }
    }
}

/**
 * Function Name: print_menu
 * Purpose: To print the menu for the user to interact with the software.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the menu out to the user.
 */

void print_menu(void) {
    printf("\n--- Student Roster Menu ---\n1. Add Student\n2. Print Roster\n3. Search by Last Name\n4. Update Student Grade\n5. Find Student with Highest Grade\n6. Calculate Class Average\n7.Exit\n");
}

/**
 * Function Name: add_student
 * Purpose: This function adds a student to the roster with all the necessary fields
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A pointer to the total number of students in the class
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Increments the total students through a pointer when a student is added.
 */

void add_student(struct student roster[], int *num_students) {
    // Check if the num of students in the class equals the max class size allowed
    if(*num_students == MAX_CLASS_SIZE) {
        printf("\nClass roster is full.\n");
        return;
    }

    bool valid_input = false;

    // Declare buffers to collect the student information
    char first_name_buff[MAX_BUFFER_SIZE];
    char last_name_buff[MAX_BUFFER_SIZE];
    char id_buff[MAX_BUFFER_SIZE];
    char grade_buff[MAX_BUFFER_SIZE];

    // Prompt user for first name
    printf("\nEnter first name: ");
    fgets(first_name_buff, sizeof(first_name_buff), stdin);
    remove_newline(first_name_buff);
    strcpy(roster[*num_students].first_name, first_name_buff);

    // Prompt user for last name
    printf("Enter last name: ");
    fgets(last_name_buff, sizeof(last_name_buff), stdin);
    remove_newline(last_name_buff);
    strcpy(roster[*num_students].last_name, last_name_buff);

    // Prompt user for ID
    printf("Enter student ID: ");
    fgets(id_buff, sizeof(id_buff), stdin);
    sscanf(id_buff, "%d", &roster[*num_students].student_id);

    // Loop to make sure grade is within proper boundaries
    do
    {
        printf("Enter grade (as a %%): ");
        fgets(grade_buff, sizeof(grade_buff), stdin);
        sscanf(grade_buff, "%lf", &roster[*num_students].grade);

        // Make sure grade is within the proper bounds
        if(roster[*num_students].grade >= 0 && roster[*num_students].grade <= 100) {
            valid_input = true;
        }
        else {
            printf("\nGrade is not valid. Enter again\n");
        }
    } while (!valid_input);
    
    (*num_students)++;
    
    printf("\nStudent added. Total Class Size: %d student(s)\n", *num_students);
}

/**
 * Function Name: print_roster
 * Purpose: This function prints the entire class roster to the terminal.
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A integer value representing the total number of students in the class.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the entire class roster to the terminal.
 */

void print_roster(struct student roster[], int num_students) {
    printf("\n--- Class Roster (%d Student(s)) ---\n", num_students);
    
    // Loop through class roster
    for(int i = 0; i < num_students; i++) {
        printf("Student %d: %s, %s (ID: %d) - Grade: %.2lf%%\n", i + 1, roster[i].last_name, roster[i].first_name, roster[i].student_id, roster[i].grade);
    }
}

/**
 * Function Name: search_by_lastname
 * Purpose: This function searchs by last name to find a students information.
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A integer value representing the total number of students in the class.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the searched students information to the terminal.
 */

void search_by_lastname(struct student roster[], int num_students) {
    char name_to_search[MAX_NAME_SIZE];
    char last_name_buff[MAX_BUFFER_SIZE];

    // Prompt user for last name
    printf("\nEnter last name to search for: ");
    fgets(last_name_buff, sizeof(last_name_buff), stdin);
    remove_newline(last_name_buff);
    strcpy(name_to_search, last_name_buff);

    // Loop through the roster to find the last name
    for(int i = 0; i < num_students; i++) {
        // If the last name is found, print it
        if(strcmp(name_to_search, roster[i].last_name) == 0) {
            printf("\nStudent Found.\n\nStudent Information: %s, %s (ID: %d) - Grade: %.2lf%% - Index in Class: %d\n", roster[i].last_name, roster[i].first_name, roster[i].student_id, roster[i].grade, i + 1);
            return;
        }
    }

    // Print there is no last name
    printf("\nThere is no lastname - %s - in the class roster.\n", name_to_search);
}

/**
 * Function Name: update_grade
 * Purpose: This function changes a students grade to the new grade.
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A integer value representing the total number of students in the class.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Updates the grade of the student with the matching ID.
 */

void update_grade(struct student roster[], int num_students) {
    char id_buff[MAX_BUFFER_SIZE];

    int student_id = 0;

    // Prompt user for ID
    printf("\nEnter student ID to update grade: ");
    fgets(id_buff, sizeof(id_buff), stdin);
    sscanf(id_buff, "%d", &student_id);

    // Loop through until student is found
    for(int i = 0; i < num_students; i++) {
        // If the student's ID is found, update their grade
        if(student_id == roster[i].student_id) {
            printf("\nStudent Found - Name: %s %s (ID: %d), Current Grade: %.2lf%%\n", roster[i].first_name, roster[i].last_name, roster[i].student_id, roster[i].grade);
            
            double new_grade = 0.0;

            bool is_valid_grade = false;
            
            // Make sure user enters valid grade
            do
            {
                char grade_buff[MAX_BUFFER_SIZE];

                // Prompt user to enter new grade
                printf("\nEnter new grade: ");
                fgets(grade_buff, sizeof(grade_buff), stdin);
                sscanf(grade_buff, "%lf", &new_grade);

                if(new_grade < 0 || new_grade > 100) {
                    printf("\nInvalid grade. Enter a new grade between 0 and 100.\n");
                }
                else {
                    is_valid_grade = true;
                    roster[i].grade = new_grade;

                    printf("\nGrade successfully changed.\n");
                    return;
                }
            } while (!is_valid_grade);
        }
    }

    // Print the ID doesn't exist
    printf("\nThe ID - %d - doesn't exist in the roster.\n", student_id);
}

/**
 * Function Name: find_highest_grade
 * Purpose: This function finds the highest student grade in the class.
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A integer value representing the total number of students in the class.
 * 
 * Return Value(s):
 *  Returns the pointer address of the student with the highest grade.
 * 
 * Side Effect(s):
 *  None.
 */

struct student* find_highest_grade(struct student roster[], int num_students) {
    int index_highest_grade = 0;

    for(int i = 1; i < num_students; i++) {
        if(roster[i].grade > roster[index_highest_grade].grade) {
            index_highest_grade = i;
        }
    }
    
    return &roster[index_highest_grade];
}

/**
 * Function Name: grade_average
 * Purpose: This function finds the grade average of the entire class.
 * 
 * Parameter(s):
 *  roster: An array of struct student elements.
 *  num_students: A integer value representing the total number of students in the class.
 * 
 * Return Value(s):
 *  Returns the grade average as a double.
 * 
 * Side Effect(s):
 *  None.
 */

double grade_average(struct student roster[], int num_students) {
    double sum_grades = 0.0;

    // Loop through class roster and add all grades together
    for(int i = 0; i < num_students; i++) {
        sum_grades += roster[i].grade;
    }

    // Calculate average
    double average = sum_grades / num_students;
    
    return average;
}