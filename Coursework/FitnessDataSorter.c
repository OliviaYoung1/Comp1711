#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct 
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

void sortData(FITNESS_DATA data[], int rows) {
    // Sort the array in descending order of steps using bubble sort
    FITNESS_DATA temp;
    int i, j;
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < rows - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error: invalid file");
        return 1;
    }

    int buffer_size = 100;
    char line[buffer_size];
    int rows = 0;


    while (fgets(line, buffer_size, file) != NULL) {
        rows++;
    }

    rewind(file);

    FITNESS_DATA FITNESS_DATAS[rows];

    for (int i = 0; i < rows; i++) {
        fgets(line, buffer_size, file);
        char date[11];
        char time[6];
        int steps;

        tokeniseRecord(line, ',', date, time, &steps);
        strcpy(FITNESS_DATAS[i].date, date);
        strcpy(FITNESS_DATAS[i].time, time);
        FITNESS_DATAS[i].steps = steps;
    }

    fclose(file);


    sortData(FITNESS_DATAS, rows);


    strcat(filename, ".tsv");
    FILE *output_file = fopen(filename, "w");

    for (int i = 0; i < rows; i++) {
        fprintf(output_file, "%s\t%s\t%d\n", FITNESS_DATAS[i].date, FITNESS_DATAS[i].time, FITNESS_DATAS[i].steps);
    }

    fclose(output_file);

    return 0;
}
