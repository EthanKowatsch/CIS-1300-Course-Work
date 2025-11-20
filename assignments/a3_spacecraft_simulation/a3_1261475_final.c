#include "a3.h"

/**
 * Function name: run_countdown
 * Purpose: The function handles the pre-launch countdown.
 *
 * Parameter(s):
 *   count: An integer representing the time to liftoff.
 *
 * Return Value(s):
 *   A constant character pointer holding a designated message depending on the time to takeoff.
 *
 * Side Effect(s): 
 *   None.
 */

const char * run_countdown(int count) {
    // If statement to calculate the liftoff situation
    if(count == 0) {
        return "Liftoff!";
    }
    else if(count > 10) {
        return "Preparing systems... too early to launch";
    }
    else if(count >= 6) {
        return "Final system checks";
    }
    else if(count >= 1) {
        return "Engines starting";
    }
    else {
        return "Abort!";
    }
}

/**
 * Function name: run_launch_sequence
 * Purpose: The function starts the launch countdown from a specified starting number.
 *
 * Parameter(s):
 *   start_count: An int representing the starting time for the rocket countdown.
 *
 * Return Value(s):
 *   None.
 *
 * Side Effect(s): 
 *   Prints the countdown using printf.
 */

void run_launch_sequence(int start_count) {
    // Loop to count down from start_count as the start number
    while (start_count >= 0) {
        // Print countdown
        printf("T-%d: %s\n", start_count, run_countdown(start_count));

        // Decrement the countdown timer
        start_count--;
    }
}

/**
 * Function name: charge_solar_cells
 * Purpose: This functions charges the spaceships solar cells until the target energy is reached.
 *
 * Parameter(s):
 *   core_energy: Pointer to current energy levels of the spaceship.
 *   target_energy: Float that stores the target energy of the spaceship.
 *   charge_rate: Float that shows the amount of energy added per cycle.
 *
 * Return Value(s):
 *   Returns the total number of cycles needed for the spaceship to reach the target energy.
 *
 * Side Effect(s): 
 *   Updates the pointer variable core_energy.
 */

int charge_solar_cells(float *core_energy, float target_energy, float charge_rate) {
    // Declare variable to store the number of cycles needed
    int total_cycles = 0;

    // Return 0 if the charge rate is less than 0 to prevent an infinite loop
    if(charge_rate <= 0) {
        return total_cycles;
    }

    // Loop until the core_energy is equal to the target energy
    while(*core_energy < target_energy) {
        // Increase the core energy by the charge rate
        *core_energy += charge_rate;

        // Check if the core energy is greater than the target energy
        if (*core_energy > target_energy) {
            // If it is, then set the value to the target_energy
            *core_energy = target_energy;
        }

        // Increase the total cycle
        total_cycles++;
    }

    return total_cycles;
}

/**
  * Function name: simulate_asteroid_rendezvous
  * Purpose: This function calculates the distance between two asteroids approaching each other.
  *
  * Parameter(s):
  *   pos_A: Pointer to current position of asteroid A.
  *   pos_B: Pointer to current position of asteroid B.
  *   velocity_A: Float of the velocity asteroid A is moving at.
  *   velocity_B: Float of the velocity asteroid B is moving at.
  *   safety_threshold: Float of the value that is the safe distance between the asteroids.
  *
  * Return Value(s):
  *   The final distance between the asteroids safety threshold before they collide.
  *
  * Side Effect(s): 
  *   Updates the position pointer of asteroid A and asteroid B.
  */

float simulate_asteroid_rendezvous(float *pos_A, float *pos_B, float velocity_A, float velocity_B, float safety_threshold) {
    // Loop as long as the next distance is not less than the safety threshold
    while ((*pos_B - velocity_B) - (*pos_A + velocity_A) > safety_threshold) {

        // Update pointers with their respective arithmetic
        *pos_A += velocity_A;
        *pos_B -= velocity_B;
    }

    // Return the final value
    return *pos_B - *pos_A;
}

/**
 * Function name: survive_asteroid_field
 * Purpose: This function simulates a spaceship navigating an asteroid field for a set number of cycles, applying various weathering conditions like damage per wave.
 *
 * Parameter(s):
 *   core_energy: Pointer to the spaceships current core energy level.
 *   hull_integrity: Pointer to the integrity of the spaceships hull.
 *   mission_cycles: Integer value storing the total wave cycles in the mission.
 *   base_energy_drain: Float value storing the amount of energy drained each cycle.
 *   damage_per_wave: Float value storing the amount of damage done per hazardous wave cycle.
 *   wave_frequency: Integer value storing the number of waves in the mission total.
 *
 * Return Value(s):
 *   Returns the hull's integrity as a double after the mission is complete.
 *
 * Side Effect(s): 
 *   Updates the pointers *core_energy and *hull_integrity.
 */

double survive_asteroid_field(float *core_energy, double *hull_integrity, int mission_cycles, float base_energy_drain, float damage_per_wave, int wave_frequency) {
    // Loop until the current cycle equals the total mission cycle
    for(int current_cycle = 1; current_cycle <= mission_cycles; current_cycle++) {
        // Subtract the base energy drain from the core energy of the ship
        *core_energy -= base_energy_drain;

        // Check if the current cycle is a hazard wave and the wave frequency is greater than 0
        if(wave_frequency > 0 && current_cycle % wave_frequency == 0) {
            *hull_integrity -= damage_per_wave;
        }

        // Check for failure conditions
        if(*hull_integrity <= 0 || *core_energy <= 0) {
            break;
        }
    }

    return *hull_integrity;
}