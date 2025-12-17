#ifndef FUNCTION_H
#define FUNCTION_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stddef.h>
#include <string.h>

#define SIMULATION_TIME 5.0
#define POINTS_COUNT 100
#define MAX_FILENAME 256
#define MAX_LINE_LENGTH 100

//Structure to handle RC Circuit parameters
typedef struct{
    double R;
    double C;
    double V;
    int M;
} RC_params;

typedef struct{
    double T;
    double V;
} Data_Point;

typedef struct{
    Data_Point *points;
    int count;
    RC_params params;
    double T_const;
} Sim_Results;

//Global Variable
extern Sim_Results results;

//Displays
void print_welcome(void);
void print_header(void);
void print_inputParams_header(void);
void print_set_params(RC_params params);
void print_menu(void);
void print_results_header(void);

//file handling
void file_import(RC_params *params);

//Menu_functions
void main_menu(void);
int user_input(void);
void back_to_main(void);

//params_handling
void set_Resistor(RC_params *params);
void set_Capacitor(RC_params *params);
void set_Voltage(RC_params *params);
void set_Mode(RC_params *params);
void clear_buffer(void);
void enter_wait(void);

//simulation
void init_Results(Sim_Results *results);
void free_Results(void);
void run_Sim(RC_params params);
void display_Results(void);


#endif