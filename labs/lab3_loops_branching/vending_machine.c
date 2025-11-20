#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(void) {
	// Declare boolean variable to store the user is using the vending machine
	bool is_browsing = true;

	// Loop until user exits
	while (is_browsing) {
		// Declare a double variable to store the user's total amount entered
		double total_amount_paid = 0.0f;

		// Declare a variable to store the item's price
		double item_price = 0.0f;

		// Declare string variable to store items name
		char item_name[100];

		// Save integer variable for user's choice
		int user_choice;

		// Save char buffer variable for user's input
		char input_buffer[100];

		// Save char buffer for coin input
		char coin_buffer[100];

		// Prompt user to pick an item
		printf("\n--- Vending Machine ---\n1. Chips (Price: $1.25)\n2. Soda (Price: $1.50)\n3. Candy (Price: $0.75)\n4. Exit\n");
		printf("Select an item: ");
		fgets(input_buffer, sizeof(input_buffer), stdin);
		sscanf(input_buffer, "%d", &user_choice);

		// Switch statement to determine  user's order
		switch (user_choice) {
			case 1:
				// Print item and price
				printf("\n1. Chips (Price: $1.25)\nPlease insert coins (5, 10, 25):\n");

				// Save items price
				item_price = 1.25;

				// Save items name
				strcpy(item_name, "Chips");
				break;
			case 2:
				// Print item and price
                                printf("\n2. Soda (Price: $1.50)\nPlease insert coins (5, 10, 25):\n");

				// Save items price
				item_price = 1.5;

				// Save items name
                                strcpy(item_name, "Soda");
                                break;
			case 3:
                                // Print item and price
				printf("\n3. Candy (Price: $0.75)\nPlease insert coins (5, 10, 25):\n");

				// Save items price
                                item_price = 0.75;

				// Save items name
                                strcpy(item_name, "Candy");
                                break;
			case 4:
				// Print thank you message
                                printf("\nThank you for using the vending machine!\n");

				// Change the state to false
                                is_browsing = false;

				// Continue instead of break to go to the next loop iteration
				continue;
			default:
				printf("\nIncorrect Input. Try Again.\n");

				// Continue instead of break to go to the next loop iteration
				continue;
		}

		// Loop until user has paid for the total amount
		while (total_amount_paid < item_price) {
			// Declare variable to store current coin value
			int current_coin = 0;

			// Prompt user to enter coin
			printf("Insert coin: ");
			fgets(coin_buffer, sizeof(coin_buffer), stdin);
			sscanf(coin_buffer, "%d", &current_coin);

			// Check if current coin is not one of the proper values
			switch (current_coin) {
				case 5:
					// Update total amount with 5 cents
					total_amount_paid += 0.05;

					// Update user paid
					printf("Paid: $%.2lf\n", total_amount_paid);
					break;
				case 10:
					// Update total amount with 10 cents
					total_amount_paid += 0.1;

					// Update user paid
                                        printf("Paid: $%.2lf\n", total_amount_paid);
                                        break;
				case 25:
					// Update total amount with 25 cents
					total_amount_paid += 0.25;

					// Update user paid
                                        printf("Paid: $%.2lf\n", total_amount_paid);
					break;
				default:
					printf("Invalid Coin. Try Again.\n");
					break;
			}
		}

		// Output change and total
		printf("\nDispensing %s (Price: $%.2lf).\nYour Change is $%.2lf\n", item_name, item_price, (total_amount_paid - item_price));
	}

	return 0;
}
