#include "stats.h"

/** 
 * Function Name: sum_of_numbers
 * Purpose: This function sums of all the numbers stored in the array.
 * 
 * Parameter(s):
 *  num_array: Pointer to the array containing the number data.
 *  size: Integer representing the number of elements in the array.
 * 
 * Return Value(s):
 *  Returns the sum of the numbers in the data array.
 * 
 * Side Effects:
 *  None.
 */

double calculate_sum(double *num_array, int size) {
    double sum = 0.0;

    for(int i = 0; i < size; i++) {
        sum += num_array[i];
    }

    return sum;
}

/** 
 * Function Name: average_of_numbers
 * Purpose: This function finds the average of all the numbers stored in the array.
 * 
 * Parameter(s):
 *  num_array: Pointer to the array containing the number data.
 *  size: Integer representing the number of elements in the array.
 * 
 * Return Value(s):
 *  Returns the average of the numbers in the data array.
 * 
 * Side Effects:
 *  None.
 */

double calculate_average(double *num_array, int size) {
    double average = 0.0;

    double sum = calculate_sum(num_array, size);

    average = sum / size;

    return average;
}

/** 
 * Function Name: find_max
 * Purpose: This function finds the maximum number in the array of numbers.
 * 
 * Parameter(s):
 *  num_array: Pointer to the array containing the number data.
 *  size: Integer representing the number of elements in the array.
 * 
 * Return Value(s):
 *  Returns the maximum number in the data array.
 * 
 * Side Effects:
 *  None.
 */

double find_max(double *num_array, int size) {
    // Set the max number to index 0 of the array
    double max_number = *(num_array + 0);

    for(int i = 0; i < size; i++) {
        // If the current index is greater than the max number, set the new max number as the current index
        if(*(num_array + i) > max_number) {
            max_number = *(num_array + i);
        }
    }

    return max_number;
}

/** 
 * Function Name: find_min
 * Purpose: This function finds the minimum number in the array of numbers.
 * 
 * Parameter(s):
 *  num_array: Pointer to the array containing the number data.
 *  size: Integer representing the number of elements in the array.
 * 
 * Return Value(s):
 *  Returns the minimum number in the data array.
 * 
 * Side Effects:
 *  None.
 */

double find_min(double *num_array, int size) {
    // Set the minimum number to index 0 of the array
    double min_number = *(num_array + 0);

    for(int i = 0; i < size; i++) {
        // If the current index is less than the min number, set the new min number as the current index
        if(*(num_array + i) < min_number) {
            min_number = *(num_array + i);
        }
    }

    return min_number;
}

/** 
 * Function Name: reverse_array
 * Purpose: This function reverses the original array.
 * 
 * Parameter(s):
 *  num_array: Pointer to the array containing the number data.
 *  size: Integer representing the number of elements in the array.
 * 
 * Return Value(s):
 *  None.
 * 
 * Side Effects:
 *  Modifies the input array in-place by reversing the elements.
 */

void reverse_array(double *num_array, int size) {
    // Declare variable to store the last index
    int last_index = size - 1;

    // Declare variable to store the size in half to make sure we don't go past the middle
    int middle_size = size / 2;

    // Loop through the array until the middle switch each value
    for(int i = 0; i < middle_size; i++) {
        // Declare a current value to the index the array is at
        double current_value = num_array[i];

        // Store a temporary value holding the last index value
        double temp_num = num_array[last_index];

        // Set the last index to be the first indexes value
        num_array[last_index] = current_value;

        // Set the current index value to be the temporary value
        num_array[i] = temp_num;

        last_index--;
    }
}