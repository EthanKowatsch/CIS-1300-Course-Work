#include <stdio.h>
#include "stats.h"

#define MAX_SIZE 10

int main(void) {
    double number_data[MAX_SIZE];
    char size_buffer[100];
    int current_size = 0;

    printf("How many numbers would you like to enter (up to 10)? ");
    fgets(size_buffer, sizeof(size_buffer), stdin);
    sscanf(size_buffer, "%d", &current_size);

    // Prevent the size entered from the user being above the max size or below 1
    if(current_size > MAX_SIZE) {
        printf("Size set to 10. %d is an invalid size.\n\n", current_size);
        current_size = MAX_SIZE;
    }
    else if(current_size <= 0) {
        printf("Size set to 1. %d is an invalid size.\n\n", current_size);
        current_size = 1;
    }
    
    printf("\n");

    // Loop to fill the array with the numbers entered by the user
    for(int i = 0; i < current_size; i++) {
        char arr_buffer[100];
        printf("Enter number %d: ", i + 1);
        fgets(arr_buffer, sizeof(arr_buffer), stdin);
        sscanf(arr_buffer, "%lf", &number_data[i]);
    }

    // Print the output of each function
    printf("\n--- Statistics ---\n");
    printf("Sum: %.2lf\n", calculate_sum(number_data, current_size));
    printf("Average: %.2lf\n", calculate_average(number_data, current_size));
    printf("Max: %.2lf\n", find_max(number_data, current_size));
    printf("Min: %.2lf\n", find_min(number_data, current_size));

    // Reverse the array output
    printf("\nArray reversed:\n");
    reverse_array(number_data, current_size);
    for(int i = 0; i < current_size; i++) {
        printf("%.2lf\n", number_data[i]);
    }
    
    return 0;
}