#include <stdio.h>
#include <stdbool.h>

int main(void) {
	// Variable to store user's name
	char array[50];

	// Get user's name
	printf("Enter your name:\n");
	scanf("%s", array);

	// Print greeting message to user
	printf("\nHello %s, I am Gryphon.AI, your AI assistant.\n", array);

	// Clear the newline
        getchar();

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
		char buffer[100];

		// Prompt user to enter number of queries
		printf("\nEnter number of new queries:\n");
		fgets(buffer, sizeof(buffer), stdin);
		sscanf(buffer, "%d", &user_queries);

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

	// Prompt user to make next decision
	printf("\nEnter a command (s)tatus, (h)elp, (q)uit: ");
	scanf(" %c", &user_decision);

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
