#include <stdio.h>
#include <stdlib.h> // Defines exit().

//automating the opening file process using a function
FILE *open_file(char filename[], char mode[]){ //mode generalises the function to all classes
    FILE *file = fopen(filename, mode);
    if (file == NULL){
        perror("");
        exit(1); //exits program with return status 1
    }
    return file;
}

int main() {
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100;
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL) {
        printf("%d\n", atoi(line_buffer));
    }

    fclose(file);
    return 0;
}