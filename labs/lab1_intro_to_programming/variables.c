#include <stdio.h>

int main() {
	// Declare variables of different types
	int an_int = 42;
	float a_float = 98.6f;
	double a_double = 234.567f;
	char a_char = 'C';

	// Perform an arithmetic operation
	double division_result = 10.0 / 3.0; // this is floating point division

	// Use the sizeof operator
	printf("---Exploring C Data Types ---\n\n");
	printf("An integer: %d\n", an_int);
	printf("A float: %f\n", a_float);
	printf("A double: %lf\n", a_double);
	printf("A char: %c\n\n", a_char);

	printf("--- Expressions and Sizes ---\n\n");
	printf("Dividing 10.0 / 3.0 equals: %f\n", division_result);
	printf("The size of an int on this system is %zu bytes.\n", sizeof(int));
	printf("The size of a double on this system is %zu bytes.\n", sizeof(a_double));
	return 0;
}
