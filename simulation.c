#include "function.h"

void init_Results(Sim_Results *results){
    results->points = NULL;
    results->count = 0;
    results->T_const = 0.00;
    results->params.R = 0.00;
    results->params.C = 0.00;
    results->params.V = 0.00;
    results->params.M = 0;
}

void free_Results(void){
    if(results.points != NULL){
        free(results.points); // avoid memory leaks
        results.points = NULL; //avoid accidental reuse
    }
    results.count = 0;
    results.T_const = 0.0;
}

void run_Sim(RC_params params) {
    if (params.R <= 0 || params.C <= 0 || params.V <= 0) {
        printf("Error!\n");
        printf("Please make sure all parameters have valid values.\n");
        printf("=== Current Values ===\n");
        printf("Resistor: %.2fΩ\n", params.R);
        printf("Capacitor: %.2eF\n", params.C);
        printf("Voltage: %.2fV\n", params.V);
        printf("Mode: %s\n", params.M == 1 ? "Charging" : "Discharging");
        enter_wait();
        return;
    }
    
    // Calculate time constant τ = R × C
    double tau = params.R * params.C;
    results.T_const = tau;
    
    // Free previous results if any
    free_Results();
    
    // Allocate memory for data points
    results.count = POINTS_COUNT;
    results.points = (Data_Point *)malloc(POINTS_COUNT * sizeof(Data_Point));
    
    if (results.points == NULL) {
        printf("Memory allocation failed!\n");
        results.count = 0;
        enter_wait();
        return;
    }
    
    // Copy parameters to global results
    results.params = params;
    double max_time = SIMULATION_TIME * tau;
    
    for (int i = 0; i < POINTS_COUNT; i++) {
        double t = (i * max_time) / (POINTS_COUNT - 1);
        double voltage;
        
        if (params.M == 1) {  // Charging mode
            // V(t) = Vs * (1 - e^(-t/τ))
            voltage = params.V * (1.0 - exp(-t / tau));
        } else {  // Discharging mode
            // V(t) = Vs * e^(-t/τ)
            voltage = params.V * exp(-t / tau);
        }
        
        results.points[i].T = t;
        results.points[i].V = voltage;
    }
    
    print_header();
    printf("Simulation completed successfully!\n");
    printf("Time constant (τ): %.4e seconds\n", tau);
    printf("Simulated %.4f seconds (%.1f time constants)\n", max_time, SIMULATION_TIME);
    printf("Generated %d data points\n", POINTS_COUNT);
    enter_wait();
}

void display_Results(void){
    if(results.count == 0 || results.points == NULL){
        printf("Error! No simulation results to display.\n");
        printf("Please run a simulation first.\n");
        enter_wait();
        return;
    }
    print_results_header();
    int rows = (results.count > 20) ? 20 : results.count;

    for (int i = 0; i < rows; i++) {
        double time = results.points[i].T;
        double voltage = results.points[i].V;

        /* Current calculation: I = (Vs - Vc) / R */
        double current;
        if (results.params.M == 1) {  // Charging
            current = (results.params.V - voltage) / results.params.R;
        } else {                      // Discharging
            current = voltage / results.params.R;
        }

        /* Charge percentage */
        double charge_percent = (voltage / results.params.V) * 100.0;

        printf("| %10.4f | %10.4f | %10.4f | %10.2f |\n",
               time, voltage, current, charge_percent);
    }

    printf("-----------------------------------------------------\n");
    printf("\n=== Simulation Summary ===\n");
    printf("Time constant (τ): %.4f seconds\n", results.T_const);
    printf("Total points: %d\n", results.count);
    printf("Mode: %s\n", results.params.M == 1 ? "Charging" : "Discharging");
    
    back_to_main(); 
}