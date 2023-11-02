#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
int rows = 0; //holds the number of records

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);
}

// Complete the main function
int main() {
    //reading the file
    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("");
        return 1;
    }
    //adding all rows into data array and counting rows
    char data[100][100];
    int buffer_size = 100; 
    char line_buffer[buffer_size];
    while (fgets(data[rows], buffer_size, file) != NULL){
        rows++;
        }
    fclose(file);
    printf("Number of records in file: %d\n", rows);

    //tokensing the records and adding to the structue
    FITNESS_DATA FITNESS_DATAS [rows];
    int a;
    for (a = 0; a < rows; a++)
    {
        char date[11];
        char time[6];
        char steps[10];
        tokeniseRecord(data[a], ",", date, time, steps);
        strcpy(FITNESS_DATAS[a].date, date);
        strcpy(FITNESS_DATAS[a].time, time);
        FITNESS_DATAS[a].steps = atoi(steps);
    }

    printf("%s/%s/%d\n", FITNESS_DATAS[0].date, FITNESS_DATAS[0].time, FITNESS_DATAS[0].steps);
    printf("%s/%s/%d\n", FITNESS_DATAS[1].date, FITNESS_DATAS[1].time, FITNESS_DATAS[1].steps);
    printf("%s/%s/%d\n", FITNESS_DATAS[2].date, FITNESS_DATAS[2].time, FITNESS_DATAS[2].steps);
    
    return 0;


    
}