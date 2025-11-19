#include <stdio.h>
#include <stdbool.h>
#include "roster.h"

int main(void) {
    // Declare a variable of type student to store the class roster
    struct student class_roster[MAX_CLASS_SIZE];
    int num_students = 0;

    bool is_active = true;

    // Loop until user exits program
    do
    {
        char user_choice_buff[MAX_BUFFER_SIZE];
        int user_choice = 0;

        // Print menu and prompt user to make their decision
        print_menu();
        printf("Select an option: ");
        fgets(user_choice_buff, sizeof(user_choice_buff), stdin);
        sscanf(user_choice_buff, "%d", &user_choice);

        // Choose action based on user's choice
        switch (user_choice) {
            case 1:
                add_student(class_roster, &num_students);
                break;
            case 2:
                if(num_students == 0) {
                    printf("\nThere are no students in the class.\n");
                }
                else {
                    print_roster(class_roster, num_students);
                }

                break;
            case 3:
                if(num_students == 0) {
                    printf("\nThere are no students in the class.\n");
                }
                else {
                    search_by_lastname(class_roster, num_students);
                }

                break;
            case 4:
                if(num_students == 0) {
                    printf("\nThere are no students in the class.\n");
                }
                else {
                    update_grade(class_roster, num_students);
                }

                break;
            case 5:
                if(num_students == 0) {
                    printf("\nThere are no students in the class.\n");
                }
                else {
                    struct student *highest = find_highest_grade(class_roster, num_students);
                    printf("\nStudent with highest grade:\n%s, %s (ID: %d) - Grade: %.2lf%%\n", highest->last_name, highest->first_name, highest->student_id, highest->grade);
                }

                break;
            case 6:
                if(num_students == 0) {
                    printf("\nThere are no students in the class.\n");
                }
                else {
                    printf("\nThe Grade Average of the Class is: %.2lf%%\n" ,grade_average(class_roster, num_students));
                }

                break;
            case 7:
                printf("\nExiting program.\n");
                is_active = false;
                break;
            default:
                printf("\nInvalid input. Try again.\n");
                break;
            }
        } while (is_active);
    

    return 0;
}