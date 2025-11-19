#include <stdio.h>

int main(void) {
	// Declare an integer variable to store total seconds
	int total_seconds = 5000;

	// Declare integer variable to store hours
	int hours = 0;

	// Declare integer variable to store minutes
	int minutes = 0;

	// Declare integer variable to store seconds
	int seconds = 0;

	// Calculate total hours (3600 in an hour)
	hours = total_seconds / 3600;

	// Calculate total minutes
	minutes = (total_seconds % 3600) / 60;

	// Calculate total seconds (take off hours first, then remove the minutes and whats left is the seconds)
	seconds = (total_seconds % 3600) % 60;

	// Print the total time in hours:minutes:seconds format
	printf("%d seconds is equal to %d:%d:%d\n", total_seconds, hours, minutes, seconds);
	return 0;
}
