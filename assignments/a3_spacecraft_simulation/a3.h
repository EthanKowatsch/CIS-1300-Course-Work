#ifndef A3_H
#define A3_H

#include <stdio.h>

const char * run_countdown(int count);
void run_launch_sequence(int start_count);
int charge_solar_cells(float *core_energy, float target_energy, float charge_rate);
float simulate_asteroid_rendezvous(float *pos_A, float *pos_B, float velocity_A, float velocity_B, float safety_threshold);
double survive_asteroid_field(float *core_energy, double *hull_integrity, int mission_cycles, float base_energy_drain, float damage_per_wave, int wave_frequency);

#endif