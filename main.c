#include "function.h"

//Define global variable
Sim_Results results;

int main(void){
    //initialise
    init_Results(&results);
    //Only prints the welcome once upon startup
    print_welcome();
    //Calls the main menu
    main_menu();
    return 0;
}