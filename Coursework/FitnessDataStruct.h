#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);

void fewest_steps(FITNESS_DATA* dataArray, int counter)
{
	int lowest_index = 0, lowest_steps = dataArray[0].steps, x;
	
    for (x = 0; x < counter; x++)
    {
		if (dataArray[x].steps < lowest_steps){
			lowest_index == x;
			lowest_steps == dataArray[x].steps;
		}
	}
	printf("Fewest steps: %s %s %d\n", dataArray[0].date, dataArray[0].time, dataArray[0].steps);

}
#endif // FITNESS_DATA_STRUCT_H