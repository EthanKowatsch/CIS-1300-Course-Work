#include <stdio.h>
#include <math.h>

int main(void) {
	// Declare variable to store the priniple
	double principal = 1000.0;

	// Declare variable to store the rate
	double rate = 0.05;

	// Declare variable to store the time in years
	double time_years = 10.0;

	// Declare variable to store the compounds per year
	double compounds_per_year = 12;

	// Declare variable to store the final amount
	double final_amount = 0;

	// Calculate final amount using the compound interest formula
	final_amount = principal * pow(1 + (rate / compounds_per_year), compounds_per_year * time_years);

	// Print final amount
	printf("After %.2lf years, an initial investment of $%.2lf at %.2lf%% compounded monthly with be worth $%.2lf.\n", time_years, principal, (rate * 100), final_amount);

	return 0;
}
