#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file


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
    char choice;
    int counter = 0;
    int buffer_size = 100; 
    char filename [100];
    char line[buffer_size];
    int mean;
    int rounded_mean;

    //get file name 
    printf("Please enter the name of the data file: ");
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    //read the file
    FILE *file = fopen(filename, "r"); 
    if (file == NULL) {
        perror("");
        return 1;
    }

    //adding all the rows into data array and counting rows
    char data[100][100];
    char line_buffer[buffer_size];
    while (fgets(data[counter], buffer_size, file) != NULL){
        counter++;
        }
    fclose(file);

    //tokensing records and adding to structue
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
        //mean to be used in task E
        mean = mean + FITNESS_DATAS[a].steps;
    }

    //for task c
    int lowest_value = FITNESS_DATAS[0].steps, lowest_index = 0;
    //for task d
    int highest_value = FITNESS_DATAS[0].steps, highest_index = 0;
    //for task f
    int currentStart = 0, currentEnd = 0, longestStart = 0, longestEnd = 0;
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
            switch (choice)
            {
            case 'A':
            case 'a':
            //calls the main function again to allow the user to change the file
                main();
                break;
            case 'B':
            case 'b':
                printf("Total records: %d\n", counter);
                break;
            case 'C':
            case 'c':
            //finds the lowest value
                for (int i = 1; i < counter; i++) {        
                    if (FITNESS_DATAS[i].steps < lowest_value){
                        lowest_value == FITNESS_DATAS[i].steps;
                        lowest_index = i;
                    }
                } 
                printf("%s %s\n", FITNESS_DATAS[lowest_index].date, FITNESS_DATAS[lowest_index].time);  
                break;

            case 'D':
            case 'd':
            //finds highest value
                for (int j = 1; j < counter; j++) {       
                    if (FITNESS_DATAS[j].steps > highest_value){
                        highest_value = FITNESS_DATAS[j].steps;
                        highest_index = j;
                    }
                } 
                printf("%s %s\n", FITNESS_DATAS[highest_index].date, FITNESS_DATAS[highest_index].time);  
                break;

            case 'E':
            case 'e':
            //finds mean
                mean = mean / counter;
                printf("Mean step count: %d\n", mean);
                break;

            case 'F':
            case 'f':
            //finds longest period >500
                for (int i = 0; i < counter; i++) {
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
                break;

            case 'Q':
            case 'q':
            //exits all recurive loops
                exit(0);

            // if they type anything else:
            default:
                printf("Invalid choice\n");
                break;
            }
        }
}
