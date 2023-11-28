#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Helper function prototypes
void tokeniseRecord(const char *input, const char *delimiter, char *date, char *time, char *steps);
void file_choice(char filename[], FITNESS_DATA FITNESS_DATAS[], int *rows);
void total_records(int rows);
void fewest_steps(FITNESS_DATA FITNESS_DATAS[], int rows);
void highest_steps(FITNESS_DATA FITNESS_DATAS[], int rows);
void mean_steps(FITNESS_DATA FITNESS_DATAS[], int rows);
void above_500(FITNESS_DATA FITNESS_DATAS[], int rows);



#endif // FITNESS_DATA_STRUCT_H