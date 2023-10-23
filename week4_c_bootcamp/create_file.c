#include <stdio.h>
int main() {
    char filename [] = "data.txt";
    FILE *file = fopen(filename, "w"); //creates a file pointer, w for write, r for read, a for append
    if (file == NULL) //an error produces a null error
    {
        perror("");
        return 1;
    }
    fclose(file); //need to close files before returning
    return 0;
}