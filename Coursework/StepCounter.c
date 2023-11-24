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


// Complete the main function
int main() {

    int buffer_size = 100;
    char line[buffer_size];
    char filename[buffer_size];
    // get the filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("");
        return 1;
    }
    //adding all rows into data array and counting rows
    char data[100][100];
     
    char line_buffer[buffer_size];
    while (fgets(data[counter], buffer_size, file) != NULL){
        counter++;
        }
    fclose(file);
    //tokensing the records and adding to the structue
    FITNESS_DATA FITNESS_DATAS [counter];
    int a;
    for (a = 0; a < counter; a++)
    {
        char date[11];
        char time[6];
        char steps[10];
        tokeniseRecord(data[a], ",", date, time, steps);
        strcpy(FITNESS_DATAS[a].date, date);
        strcpy(FITNESS_DATAS[a].time, time);
        FITNESS_DATAS[a].steps = atoi(steps);
    }
    printf("%s", FITNESS_DATAS[a].date);

    while (1)
        {
            printf("A: Specify the filename to be imported\n");
            printf("B: Display the total number of records in the file\n");
            printf("C: Find the date and time of the timeslot with the fewest steps\n");
            printf("D: Find the data and time of the timeslot with the largest number of steps\n");
            printf("E: Find the mean step count of all the records in the file\n");
            printf("F: Find the longest continuous period where the step count is above 500 steps\n");
            printf("Q: Exit\n");

            // get the next character typed in and store in the 'choice'
            choice = getchar();

            // this gets rid of the newline character which the user will enter
            // as otherwise this will stay in the stdin and be read next time
            while (getchar() != '\n');

            // switch statement to control the menu.
            switch (choice)
            {
            // this allows for either capital or lower case
            case 'A':
            case 'a':
                main();
                break;
            case 'B':
            case 'b':
                printf("Total records: %d\n", counter);
                break;
            case 'C':
            case 'c':
                

                break;

            case 'D':
            case 'd':
                return 0;
                break;

            case 'E':
            case 'e':
                return 0;
                break;

            case 'F':
            case 'f':
                return 0;
                break;

            case 'Q':
            case 'q':
                exit(0);

            // if they type anything else:
            default:
                printf("Invalid choice\n");
                break;
            }
        }
}
