#include <stdio.h>

int main(void) {
	// Declare integer variables
	int a = 20;
	int b = 99;

	// Print initial value
	printf("Before swap: a = %d, b = %d\n", a, b);

	// Declare temp variable to hold swapped value
	int temp = 0;

	// Swap values by first setting temp to equal "a"
	temp = a;
	// Then save "a" to equal the value in "b"
	a = b;
	// Then set "b" to equal the temp value
	b = temp;

	// Print the final output
	printf("After swap: a = %d, b = %d\n", a, b);

	return 0;
}
