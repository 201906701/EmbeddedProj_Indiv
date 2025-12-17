#include "function.h"

void file_import(RC_params *params) {
    char filename[MAX_FILENAME];
    FILE *file;
    double R = 0, C = 0, V = 0;
    int M = 0;
    
    print_inputParams_header();
    printf("Enter filename to import parameters from: ");
    
    if (fgets(filename, sizeof(filename), stdin) == NULL) {
        printf("Error! Error reading filename.\n");
        enter_wait();
        return;
    }
    filename[strcspn(filename, "\n")] = '\0';
    
    if (strlen(filename) == 0) {
        printf("No filename entered.\n");
        enter_wait();
        return;
    }
    
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error! Cannot open file '%s' for reading.\n", filename);
        enter_wait();
        return;
    }
    
    printf("\nReading parameters from file: %s\n", filename);
    printf("------------------------------------------\n");
    
    if (fscanf(file, "%lf %lf %lf %d", &R, &C, &V, &M) != 4) {
        printf("Error! Invalid file format.\n");
        printf("Expected: R_value C_value V_value Mode\n");
        printf("Example: 1000 0.001 5.0 1\n");
        fclose(file);
        enter_wait();
        return;
    }
    
    fclose(file);
    
    // Validate values
    if (R <= 0 || C <= 0 || V <= 0 || (M != 0 && M != 1)) {
        printf("Error! Invalid values in file.\n");
        printf("All values must be positive, Mode must be 0 or 1\n");
        enter_wait();
        return;
    }
    
    // Update parameters
    params->R = R;
    params->C = C;
    params->V = V;
    params->M = M;
    results.params.R = R;
    results.params.C = C;
    results.params.V = V;
    results.params.M = M;
    
    printf("\nParameters imported successfully:\n");
    printf("------------------------------------------\n");
    printf("Resistor: %.4f Ω\n", R);
    printf("Capacitor: %.4e F\n", C);
    printf("Voltage: %.4f V\n", V);
    printf("Mode: %s\n", M == 1 ? "Charging" : "Discharging");
    printf("------------------------------------------\n");
    
    enter_wait();
}