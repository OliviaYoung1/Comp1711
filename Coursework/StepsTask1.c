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
char record= [];
int i;


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
    //char record = [[],[],[]];
    int rows = 0; //holds the number of records

    char filename [] = "FitnessData_2023.csv";
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("");
        return 1;
    }

    int buffer_size = 100; 
    char line_buffer[buffer_size];
    while (fgets(line_buffer, buffer_size, file) != NULL){
        printf("%s", line_buffer);
        record.append(line_buffer);
        rows++;
    int records_to_print = 0;
    for (i==0; i == rows; i++){
        tokeniseRecord(record[i], ",", date, time, steps);
        records_to_print++;
        if (records_to_print < 4){
            printf("%s/%s/%s", date, time, steps);
        }
    }
    }
    fclose(file);
    printf("Number of records in file: %d\n", rows);
    return 0;
    


}
