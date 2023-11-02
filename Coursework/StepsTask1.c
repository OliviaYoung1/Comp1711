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
    int rows = 0; //holds the number of records

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("");
        return 1;
    }
    char data[100][100];
    int buffer_size = 100; 
    char line_buffer[buffer_size];
    while (fgets(data[rows], buffer_size, file) != NULL){
        rows++;
        }
    fclose(file);
    printf("Number of records in file: %d\n", rows);

    FITNESS_DATA FITNESS_DATAS[rows];
    int x;
    for (x = 0; x < rows ; x++){
       char date[11];
       char time[6];
       char steps[10]; 
       //printf("%s", data[x]); 
       tokeniseRecord(data[x], ",", date, time, steps);
        FITNESS_DATAS[x].date == date;
        FITNESS_DATAS[x].time == time;
        FITNESS_DATAS[x].steps == 10;
        printf("%s\n", FITNESS_DATAS[x].date);

    }
    //printf("%s/%s/%d", FITNESS_DATAS[0].date, FITNESS_DATAS[0].time, FITNESS_DATAS[0].steps);
    //printf("%s/%s/%d", FITNESS_DATAS[1].date, FITNESS_DATAS[1].time, FITNESS_DATAS[1].steps);
    //printf("%s/%s/%d", FITNESS_DATAS[2].date, FITNESS_DATAS[2].time, FITNESS_DATAS[2].steps);
    return 0;
}


