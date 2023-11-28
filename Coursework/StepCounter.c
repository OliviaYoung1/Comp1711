#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
// Global variables for filename and FITNESS_DATA array


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


void file_choice(char filename[], FITNESS_DATA FITNESS_DATAS[], int *rows){
    rows = 0;
	FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error: could not open file");
        exit(1);
    }

    int buffer_size = 100;
    char line[buffer_size];

    while (fgets(line, buffer_size, file) != NULL) {
        char date[11];
        char time[6];
        char str_steps[10];
        tokeniseRecord(line, ",", date, time, str_steps);
        strcpy(FITNESS_DATAS[*rows].date, date);
        strcpy(FITNESS_DATAS[*rows].time, time);
        FITNESS_DATAS[*rows].steps = atoi(str_steps);
        (*rows)++;
    }

    fclose(file);

}
void total_records(int rows){
	printf("Total records: %d\n", rows);
}
void fewest_steps(FITNESS_DATA FITNESS_DATAS[], int rows){
	int min_steps = 0;
	int index = 0;
	for (int i = 0; i < rows; i++) {
		if (FITNESS_DATAS[i].steps < min_steps) {
            min_steps = FITNESS_DATAS[i].steps;
            index = i;
		}
	}

	printf("Fewest steps: %s %s\n", FITNESS_DATAS[index].date, FITNESS_DATAS[index].time);
}

void highest_steps(FITNESS_DATA FITNESS_DATAS[], int rows){
	int max_steps = 0;
    int index = 0;

    for (int i = 0; i < rows; i++) {
        if (FITNESS_DATAS[i].steps > max_steps) {
            max_steps = FITNESS_DATAS[i].steps;
            index = i;
        }
    }
	printf("Largest steps: %s %s\n", FITNESS_DATAS[index].date, FITNESS_DATAS[index].time);
}


void mean_steps(FITNESS_DATA FITNESS_DATAS[], int rows){
	int total_steps = 0;

    for (int i = 0; i < rows; i++) {
        total_steps = total_steps + FITNESS_DATAS[i].steps;
    }

	float mean_steps = total_steps / rows;
	int rounded_mean = mean_steps + 0.5;
    printf("Mean step count: %d\n", rounded_mean);
}


void above_500(FITNESS_DATA FITNESS_DATAS[], int rows){
	int currentStart = 0, currentEnd = 0, longestStart = 0, longestEnd = 0;
	for (int i = 0; i < rows; i++) {
        if (FITNESS_DATAS[i].steps > 500) {
        // If the current period is ongoing, update the ending index
        currentEnd = i;
        } else {
            // If the current period is not ongoing, check if it's the longest
            if (currentEnd - currentStart > longestEnd - longestStart) {
                longestStart = currentStart;
                longestEnd = currentEnd;
            }
            // Reset the current period
            currentStart = currentEnd = i + 1;
        }
    }
                
    // Check for the last continuous period
    if (currentEnd - currentStart > longestEnd - longestStart) {
        longestStart = currentStart;
        longestEnd = currentEnd;
    }
    printf("Longest period start:%s %s\n", FITNESS_DATAS[longestStart].date, FITNESS_DATAS[longestStart].time);
    printf("Longest period end:%s %s\n", FITNESS_DATAS[longestEnd].date, FITNESS_DATAS[longestEnd].time);
               
}


// Complete the main function
int main() {
   char filename[100];
    int choice;
    int rows = 0;
    FITNESS_DATA FITNESS_DATAS[100];

    while (1)
    {
        printf("A: Specify the filename to be imported\n");
        printf("B: Display the total number of records in the file\n");
        printf("C: Find the date and time of the timeslot with the fewest steps\n");
        printf("D: Find the data and time of the timeslot with the largest number of steps\n");
        printf("E: Find the mean step count of all the records in the file\n");
        printf("F: Find the longest continuous period where the step count is above 500 steps\n");
        printf("Q: Exit\n");

        //gets users choice
        choice = getchar();
        while (getchar() != '\n');
        // controls the menu
        switch (choice){
            case 'A':
            case 'a':
                printf("Input filename:");
                scanf("%s", filename);
                file_choice(filename, FITNESS_DATAS, &rows);
                break;
            
            case 'B':
            case 'b':
                total_records(rows);
                break;

            case 'C':
            case 'c':
                fewest_steps(FITNESS_DATAS, rows);
                break;

            case 'D':
            case 'd':
                highest_steps(FITNESS_DATAS, rows);
                break;

            case 'E':
            case 'e':
                mean_steps(FITNESS_DATAS, rows);
                break;

            case 'F':
            case 'f':
                above_500(FITNESS_DATAS, rows);
                break;

            case 'Q':
            case 'q':
                return 0;
                break;

            default:
                printf("Invalid choice.\n");
    }

}
}


