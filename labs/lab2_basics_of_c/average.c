#include <stdio.h>

int main(void) {
	// Declare score variables
	int score1 = 95;
	int score2 = 88;
	int score3 = 91;

	// Declare variable to hold the total sum of the scores
	int total = 0;

	// Calculate the total and store it
	total = score1 + score2 + score3;

	// Declare variable to store the average
	float average = 0.0f;

	// Calculate the average
	average = total / 3.0f;

	// Print output
	printf("Scores: %d, %d, %d\nTotal: %d\nAverage: %f\n", score1, score2, score3, total, average);
	return 0;
}
