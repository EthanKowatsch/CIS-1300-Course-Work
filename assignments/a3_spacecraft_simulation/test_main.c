#include <stdio.h>
#include "a3.h"

int main(void) {
    printf("=== Assignment 3: Function Tests ===\n\n");

    /* ---------------------------
       Test: run_countdown
       --------------------------- */
    printf("[run_countdown]\n");
    int countdown_tests[] = {12, 10, 6, 5, 1, 0, -3};
    int num_ct = sizeof(countdown_tests) / sizeof(int);

    for (int i = 0; i < num_ct; i++) {
        int val = countdown_tests[i];
        printf("Input: %d -> Output: %s\n", val, run_countdown(val));
    }
    printf("\n");

    /* ---------------------------
       Test: run_launch_sequence
       --------------------------- */
    printf("[run_launch_sequence]\n");
    run_launch_sequence(8);
    printf("\n");

    /* ---------------------------
       Test: charge_solar_cells
       --------------------------- */
    printf("[charge_solar_cells]\n");
    float energy = 40.0f;
    int cycles = charge_solar_cells(&energy, 100.0f, -5.0f);
    printf("Cycles needed: %d\n", cycles);
    printf("Final energy: %.2f\n\n", energy);

    /* ---------------------------
       Test: simulate_asteroid_rendezvous
       --------------------------- */
    printf("[simulate_asteroid_rendezvous]\n");
    float posA = 0.0f, posB = 1200.0f;
    float dist = simulate_asteroid_rendezvous(&posA, &posB, 40.0f, 60.0f, 100.0f);
    printf("Final pos A: %.2f\n", posA);
    printf("Final pos B: %.2f\n", posB);
    printf("Final distance: %.2f\n\n", dist);

    /* ---------------------------
       Test: survive_asteroid_field
       --------------------------- */
    printf("[survive_asteroid_field]\n");

    // Test case: expected survival
    float energy_s = 90.0f;
    double hull_s = 100.0;
    double final_hull_s = survive_asteroid_field(&energy_s, &hull_s, 12, 4.0, 8.0, 0);

    printf("Case 1: Survived? %s\n", final_hull_s > 0 ? "Yes" : "No");
    printf("Final energy: %.2f | Final hull: %.2f\n\n", energy_s, final_hull_s);

    // Test case: expected failure
    float energy_f = 90.0f;
    double hull_f = 40.0;
    double final_hull_f = survive_asteroid_field(&energy_f, &hull_f, 12, 4.0, 8.0, 0);

    printf("Case 2: Survived? %s\n", final_hull_f > 0 ? "Yes" : "No");
    printf("Final energy: %.2f | Final hull: %.2f\n\n", energy_f, final_hull_f);

    return 0;
}
