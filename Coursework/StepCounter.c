#include "FitnessDataStruct.h"
int main()
{
    // array of fitness data
    FITNESS_DATA [100];

    char line[buffer_size];
    char filename[buffer_size];

    // get filename from the user
    printf("Please enter the name of the data file: ");

    // these lines read in a line from the stdin (where the user types)
    // and then takes the actual string out of it
    // this removes any spaces or newlines.
    fgets(line, buffer_size, stdin);
    sscanf(line, " %s ", filename);

    char choice;
    int counter = 0;
    float mean = 0;

    counter = 0;
    FILE *input = fopen(filename, "r");
    if (!input)
    {
        printf("Error: File could not be opened\n");
        return 1;
    }
    while (fgets(line, buffer_size, input))
    {
    // split up the line and store it in the right place
    // using the & operator to pass in a pointer to the bloodIron so it stores it
    tokeniseRecord(line, ",", daily_readings[counter].date, &daily_readings[counter].bloodIron);
    counter++;
    }
    

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
                return 0;
                break;
            case 'B':
            case 'b':
                return 0;
                break;
            case 'C':
            case 'c':

                return 0;
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
                return 0;
                break;

            // if they type anything else:
            default:
                printf("Invalid choice\n");
                break;
            }
        }
}