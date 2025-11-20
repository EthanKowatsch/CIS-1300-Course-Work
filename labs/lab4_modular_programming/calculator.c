#include <stdio.h>
#include "calculator.h"

/**
 * Function Name: print_menu
 * Purpose: Print the calculator menu.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  None.
 */

void print_menu(void) {
    // Print the menu using a print statement
    printf("\n--- Calculator Menu ---\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\n");
}

/**
 * Function Name: get_user_inputs
 * Purpose: Get the user inputted numbers and store them in the number pointers.
 * 
 * Parameter(s):
 *  num1_ptr: Pointer to the first number entered by the user.
 *  num2_ptr: Pointer to the second number entered by the user.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Print statements to prompt user to enter the desired numbers
 */

void get_user_inputs(double *num1_ptr, double *num2_ptr) {
    // Create a buffer for the user's inputted numbers
    char buffer[100];

    // Prompt user to enter the first number
    printf("\nEnter the first number: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", num1_ptr);

    // Prompt user to enter the second number
    printf("Enter the second number: ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%lf", num2_ptr);
}

/**
 * Function Name: add_numbers
 * Purpose: Add the two pointer numbers.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the results of adding the two numbers.
 */

void add_numbers(void) {
    // Declare variables to store the numbers entered by the users
    double num1, num2;

    // Get the user's inputs
    get_user_inputs(&num1, &num2);

    // Print the output
    printf("Result: %.2lf\n", num1 + num2);
}

/**
 * Function Name: subtract_numbers
 * Purpose: Subtract the two pointer numbers.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the results of subtracting the two numbers.
 */

void subtract_numbers(void) {
    // Declare variables to store the numbers entered by the users
    double num1, num2;

    // Get the user's inputs
    get_user_inputs(&num1, &num2);

    // Print the output
    printf("Result: %.2lf\n", num1 - num2);
}

/**
 * Function Name: multiply_numbers
 * Purpose: Multiply the two pointer numbers.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the results of multiplying the two numbers.
 */

void multiply_numbers(void) {
    // Declare variables to store the numbers entered by the users
    double num1, num2;

    // Get the user's inputs
    get_user_inputs(&num1, &num2);

    // Print the output
    printf("Result: %.2lf\n", num1 * num2);
}

/**
 * Function Name: divide_numbers
 * Purpose: Divide the two pointer numbers as long as they don't equal zero.
 * 
 * Parameter(s):
 *  None.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effect(s):
 *  Prints the results of dividing the two numbers.
 */

void divide_numbers(void) {
    // Declare variables to store the numbers entered by the users
    double num1, num2;

    // Get the user's inputs
    get_user_inputs(&num1, &num2);

    // Prevent dividing by 0
    if(num2 == 0) {
        printf("Error: Cannot divide by zero.\n");
    }
    else {
        // Print the output
        printf("Result: %.2lf\n", num1 / num2);
    }
}