#include <stdio.h>
#include <stdbool.h>
#include "calculator.h"

int main(void) {
    // Declare integer variable to store the user's menu choice
    int user_menu_choice = 0;

    // Declare boolean variable to store if the menu is active or not
    bool is_active = true;

    // Loop unless the user chooses to exit
    while(is_active) {
        // Print menu
        print_menu();
        
        // Create buffer for the user choice
        char buffer[100];
    
        // Prompt user to select an option from the menu
        printf("Select an option: ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &user_menu_choice);

        // Switch statement to determine calculation
        switch (user_menu_choice)
        {
        case 1:
            // Add the user entered numbers
            add_numbers();
            break;
        case 2:
            // Subtract the user entered numbers
            subtract_numbers();
            break;
        case 3:
            // Multiply the user entered numbers
            multiply_numbers();
            break;
        case 4:
            // Divide the user entered numbers
            divide_numbers();
            break;
        case 5:
            // Exit program
            printf("Exiting calculator\n");

            // Set is_active to false
            is_active = false;
            break;
        default:
            // Print default case
            printf("Please enter correct value.\n");
            break;
        }
    }

    return 0;
}