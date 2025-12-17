#include "function.h"

void print_welcome(void){
    printf("------------------------------------------\n");
    printf("|             !!! Welcome !!!            |\n");
    printf("------------------------------------------\n");
    printf("Welcome to this RC Circuit Simulator\n");
    printf("This program simulates a RC Circuit based on user specifications.\n");
}

void print_header(void){
    printf("------------------------------------------\n");
    printf("|          RC Circuit Simulator          |\n");
    printf("------------------------------------------\n");
}

void print_inputParams_header(void){
    printf("------------------------------------------\n");
    printf("|    Simulation Mode: Input Parameters   |\n");
    printf("------------------------------------------\n");
}

void print_set_params(RC_params params){
    printf("=== Set Parameters ===\n");
    printf("Resistor(R): %.4fΩ\n", params.R);
    printf("Capacitor(C): %.4eF\n", params.C);
    printf("Input Voltage(Vs): %.4fV\n", params.V);
    printf("Mode: %s\n\n", params.M == 0 ? "Discharging" : "Charging");
}

void print_menu(void){
    printf("=== Main Menu ===\n");
    printf("1. Set resistor value(R)\n");
    printf("2. Set capacitor value(C)\n");
    printf("3. Set input voltage(Vs)\n");
    printf("4. Set charging/discharging mode\n");
    printf("5. Import inputs from file\n");
    printf("6. Run Simulation\n");
    printf("7. Display results\n");
    printf("8. Exit\n");
    printf("Please choose[1-8] \n");
    printf("------------------------------------------\n");
}

void print_results_header(void){
    printf("-----------------------------------------------------\n");
    printf("|                       Results                     |\n");
    printf("------------------------------------------------------\n");
    printf("|   Time(s)  | Voltage(Vc)|   Amps(A)  | Charged(%%) |\n");
    printf("-----------------------------------------------------\n");

}
