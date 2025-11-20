#include <stdio.h>
#include <stdbool.h>

int main(void) {
	// Variable to store user's name
	char name[50];

	// Declare a buffer for the input of name
	char name_buffer[100];

	// Get user's name using safer method than scanf()
	printf("Enter your name:\n");
	fgets(name_buffer, sizeof(name_buffer), stdin);
	sscanf(name_buffer, " %49s", name);

	// Print greeting message to user
	printf("Hello %s, I am Gryphon.AI, your AI assistant.\n", name);

	// Declare integer variable for queries processed amount
	int queries_processed = 0;

	// Declare float variable for cpu usage
	float cpu_usage = 10.5f;

	// Declare integer variable for memory load
	int memory_load = 20;

	// Declare boolean value to store if the entry is valid from the user
	bool is_valid = false;

	// Declare loop to prompt user for the number of new queries
	while(!is_valid) {
		// Declare variable to store user input
		int user_queries = 0;

		// Declare buffer to store user input for the number of new queries
		char queries_buffer[100];

		// Prompt user to enter number of queries
		printf("\nEnter number of new queries:\n");
		fgets(queries_buffer, sizeof(queries_buffer), stdin);
		sscanf(queries_buffer, "%d", &user_queries);

		// Check if the user entered a valid amount of queries
		if(user_queries > 0 && user_queries <= 100) {
			// Update isValid to show the user entered a valid number of queries
			is_valid = true;

			// Update queries processed
			queries_processed += user_queries;

			// Update cpu usage
			cpu_usage *= 1.2f;

			// Update memory load
			memory_load /= 2;
		}
		else {
			printf("Invalid! Enter a valid integer.\n");
		}
	}

	// Output the status update
	printf("\n-- Gryphon.AI Status Update --\nTotal Queries Processed: %d\nCPU Usage: %.2f\nMemory Load: %d\n%s\n", queries_processed, cpu_usage, memory_load, (queries_processed % 10 == 0) ? "System check recommended." : "System check not recommended.");

	// Check status
	if(cpu_usage > 50 || memory_load > 75) {
		printf("\nSTATUS: CRITICAL.\n");
	}
	else if(cpu_usage > 30 || memory_load > 50) {
		printf("\nSTATUS: WARNING.\n");
	}
	else {
		printf("\nSTATUS: NOMINAL.\n");
	}

	// Declare char variable to store users input
	char user_decision;

	// Declare buffer to store user choice input
	char decision_buffer[100];

	// Prompt user to make next decision
	printf("\nEnter a command (s)tatus, (h)elp, (q)uit: ");
	fgets(decision_buffer, sizeof(decision_buffer), stdin);
	sscanf(decision_buffer, " %c", &user_decision);

	// Switch statement for user's decision
	switch(user_decision) {
		case 's':
			printf("Displaying full system status...\n");
                        break;
		case 'h':
			printf("Help docs are available online.\n");
                        break;
		case 'q':
			printf("Shutting down. Goodbye.\n");
                        break;
		default:
			printf("Error: Unrecognized command.\n");
			break;
	}

	return 0;
}
