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
unsigned record[100];

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
    char *data[100];
    int buffer_size = 100; 
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        //printf("%s", line_buffer);
        data[rows] == line_buffer;
        rows++;
        }
    printf("%s\n", data[2]);
    fclose(file);
    printf("Number of records in file: %d\n", rows);

    char records[21] = "2023-09-01,07:30,300";
    tokeniseRecord(records, ",", date, time, steps);
    FITNESS_DATA line [] = {
        {date, time, steps}
    };
    printf("%s-%s-%d\n", date, time, steps);

    return 0;
}


