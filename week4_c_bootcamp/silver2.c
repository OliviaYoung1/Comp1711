#include <stdio.h>
#include <stdlib.h> //standard library for atoi
int main() {
    char filename[] = "squares.dat";
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("");
        return 1;
    }
    int buffer_size = 100, total = 0, lines = 0; 
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        lines = lines + 1;
        total = total + atoi(line_buffer);
    }
    printf("%d", total/lines);
    fclose(file);
    return 0;
}