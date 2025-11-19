#include <stdio.h>
#include <stdbool.h>

int main(void) {
	// Declare integer variable to store number of courses
	int num_courses = 0;

	// Declare double variable to store total points
	double total_points = 0.0f;

	// Declare doubel variable to store total GPA average
	double gpa_average = 0.0f;

	// Declare boolean variable to store whether user wants to keep entering grades or not
	bool is_active = true;

	// Do-while loop to loop while user enters courses/grades
	do {
		// Declare char variables to store the buffer for the users grade input and whether they want to continue or not
		char grade_buffer[100];
		char decision_buffer[100];

		// Declare variable to store user's entered grade and their decision
		char grade;
		char user_decision;

		// Prompt user for their letter grade
		printf("\nEnter a letter grade (A, B, C, D, F): ");
		fgets(grade_buffer, sizeof(grade_buffer), stdin);
		sscanf(grade_buffer, " %c", &grade);

		// Switch statement to add grade to GPA
		switch(grade) {
			case 'A': case 'a':
				// Increase course total
				num_courses++;

				// Add total points
				total_points += 4.0f;

				// Give user feedback grade was added
				printf("Your %c grade was added.\n", grade);
				break;
			case 'B': case 'b':
                                // Increase course total
                                num_courses++;

                                // Add total points
                                total_points += 3.0f;

                                // Give user feedback grade was added
                                printf("Your %c grade was added.\n", grade);
                                break;
			case 'C': case 'c':
                                // Increase course total
                                num_courses++;

                                // Add total points
                                total_points += 2.0f;

                                // Give user feedback grade was added
                                printf("Your %c grade was added.\n", grade);
                                break;
			case 'D': case 'd':
                                // Increase course total
                                num_courses++;

                                // Add total points
                                total_points += 1.0f;

                                // Give user feedback grade was added
                                printf("Your %c grade was added.\n", grade);
                                break;
			case 'F': case 'f':
                                // Increase course total
                                num_courses++;

                                // Give user feedback grade was added
                                printf("Your %c grade was added.\n", grade);
                                break;
			default:
				printf("Invalid grade entered. Ignoring.\n");
				break;
		}

		// Prompt user whether they want to enter more grades
		printf("Enter another grade? (y/n) ");
                fgets(decision_buffer, sizeof(decision_buffer), stdin);
                sscanf(decision_buffer, " %c", &user_decision);

		// Check user's entered prompt
		if (user_decision == 'N' || user_decision == 'n') {
			// Calculate GPA
			gpa_average = total_points / num_courses;

			// Print total GPA if user has no more classes to enter
			printf("\nGPA for %d %s: %.2lf\n", num_courses, (num_courses == 1) ? "course" : "courses", gpa_average);

			// Set value to false
			is_active = false;
		}

	} while(is_active);

	return 0;
}
