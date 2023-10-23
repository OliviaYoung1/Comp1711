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

int main(){
    char filename [] = "data.txt";
    FILE *file = open_file(filename, "r");


    int buffer_size = 100; //buffer should be longer than the largest line plus 1
    char line_buffer[buffer_size];
    //fgets reads the file line by line into a buffer
    while (fgets(line_buffer, buffer_size, file) != NULL){
        printf("%s", line_buffer);
    }
    fclose(file);
    return 0;
}