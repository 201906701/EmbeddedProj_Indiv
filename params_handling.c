#include "function.h"

void set_Resistor(RC_params *params){
    double R;

    print_inputParams_header();
    printf("Current set value: %.4fΩ\n", params->R);
    printf("Enter Resistor value(Ω): ");
    
    if(scanf("%lf", &R) != 1){
        clear_buffer();
        printf("Error! Your input was invalid.\n");
        enter_wait();
        return;
    }
    clear_buffer();

    if (R>0){
        params->R = R;
        results.params.R = R;
        printf("Resistor value set to: %.4fΩ\n", R);
    }else{
        printf("Error! Your input was invalid.\n");
    }
    enter_wait();
}

void set_Capacitor(RC_params *params){
    double C;
    
    print_inputParams_header();
    printf("Current set value: %.2eF\n", params->C);
    printf("Enter Capacitor value(F): ");
    
    if(scanf("%lf", &C) != 1){
        clear_buffer();
        printf("Error! Your input was invalid.\n");
        enter_wait();
        return;
    }
    clear_buffer();

    if (C>0){
        params->C = C;
        results.params.C = C;
        printf("Capacitor value set to: %.4eF\n", C);
    }else{
        printf("Error! Your input was invalid.\n");
    }
    enter_wait();
}

void set_Voltage(RC_params *params){
    double V;

    print_inputParams_header();
    printf("Current set value: %.2fV\n", params->V);
    printf("Enter Voltage value(Vs): ");
    
    if(scanf("%lf", &V) != 1){
        clear_buffer();
        printf("Error! Your input was invalid.\n");
        enter_wait();
        return;
    }
    clear_buffer();

    if (V>0){
        params->V = V;
        results.params.V = V;
        printf("Voltage value set to: %.4fV\n", V);
    }else{
        printf("Error! Your input was invalid.\n");
    }
    enter_wait();
}

void set_Mode(RC_params *params){
    int m;

    print_inputParams_header();
    printf("[1] Charging Mode\n");
    printf("[2] Discharging Mode\n");
    printf("Select [1] or [2]: \n");
    
    if(scanf("%d", &m) != 1){
        clear_buffer();
        printf("Error! Your input was invalid.\n");
        enter_wait();
        return;
    }
    clear_buffer();

    if(m == 1 || m == 2){
        params->M = (m==1)?1:0;
        results.params.M = params->M;
        if(m == 1){
            printf("Mode: Charging\n");
        }
        if(m == 2){
            printf("Mode: Discharging\n");
        }
    }else{
        printf("Invalid :(\n Please choose [1] or [2]\n");
    }
    enter_wait();
}

void clear_buffer(void){
    int c;
    while((c=getchar()) != '\n' && c != EOF);
}

void enter_wait(void){
    printf("\nPress [Enter] to continue\n");
    clear_buffer();
}