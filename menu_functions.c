#include "function.h"

void main_menu(void) {
    int choice;

    // condition check happens after the body runs
    do{
        print_header();
        print_set_params(results.params);
        print_menu();
        choice = user_input();
        
        switch(choice){
            case 1: set_Resistor(&results.params); break;
            case 2: set_Capacitor(&results.params); break;
            case 3: set_Voltage(&results.params); break;
            case 4: set_Mode(&results.params); break;
            case 5: file_import(&results.params); break;
            case 6: run_Sim(results.params); break;
            case 7: display_Results(); break;
            case 8: 
                printf("Bye Bye!\n");
                //prevent memory leaks
                free_Results();
                exit(0); 
                break;
            default:
                printf("Error! Please enter a number between [1-8]\n");
                enter_wait();
        }
    }while(choice !=8);
}

int user_input(void){
    int input;
    printf("\nSelect [1-8] ");

    //check if scanf suceeds
    if(scanf("%d", &input) != 1){
        clear_buffer();
        return -1; //Error Code
    }
    clear_buffer();
    return(input);
}

void back_to_main(void){
    char input;
    printf("\n");
    printf("[M] for Main Menu | [Q] to Quit Program\n");

    do{
        scanf("%c", &input);
        clear_buffer();

        if(input == 'M' || input == 'm'){
            // go back to the main menu
            return;
        }else if(input == 'Q' || input == 'q'){
            printf("Bye Bye!\n");
            free_Results();
            exit(0);
        }else{
            printf("Error! Please choose [M] or [Q]");
        }
    }while(1);
}