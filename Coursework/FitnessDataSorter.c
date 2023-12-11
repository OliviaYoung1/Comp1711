#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct 
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FITNESS_DATA;

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
        if (ptr != NULL) {
            strcpy(time, ptr);
            ptr = strtok(NULL, &delimiter);
            if (ptr != NULL) {
                *steps = atoi(ptr);
            }
        }
    }
}

void sortData(FITNESS_DATA data[], int rows) {
    // Sort the array in descending order of steps using bubble sort
    FITNESS_DATA temp;
    int i, j;
    for (i = 0; i < rows - 1; i++) {
        for (j = 0; j < rows - i - 1; j++) {
            if (data[j].steps < data[j + 1].steps) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int validate(const char *str) {
    //sees how many commas, should be 2
    int count = 0;
    while (*str) {
        if (*str == ',') {
            count++;
        }
        str++;
    }
    return count;
}

int valid_time(const char *str) {
    //sees qif time is in xx:xx format within bounds
    int hrs, mins;
    char colon;
    if (sscanf(str, "%d:%d%c", &hrs, &mins, &colon) == 2) {
        if (hrs >= 0 && hrs <= 23 && mins >= 0 && mins <= 59) {
            return 0;
        }
    }
    return 1;
}

int valid_date(const char *str) {
    //sees if date is in yyyy/mm/dd format
    int day, month, year;
    char dash1, dash2;
    if (sscanf(str, "%d-%d-%d%c", &year, &month, &day, &dash1) == 3) {
        if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 1900) {
            return 0;
        }
    }
    return 1;
}




int main() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: invalid file\n");
        return 1;
    }

    int buffer_size = 100;
    char line[buffer_size];
    int rows = 0;


    while (fgets(line, buffer_size, file) != NULL) {
        rows++;
        if (validate(line) != 2){
            printf("Error: invalid file\n");
            return 1;
        }
    }

    rewind(file);

    FITNESS_DATA FITNESS_DATAS[rows];

    for (int i = 0; i < rows; i++) {
        fgets(line, buffer_size, file);
        char date[11];
        char time[6];
        int steps;

        tokeniseRecord(line, ',', date, time, &steps);
        strcpy(FITNESS_DATAS[i].date, date);
        strcpy(FITNESS_DATAS[i].time, time);
        FITNESS_DATAS[i].steps = steps;
        if (strlen(FITNESS_DATAS[i].date) != 10 || FITNESS_DATAS[i].steps < 0 || FITNESS_DATAS[i].steps >= 500000){
            printf("Error: invalid file\n");
            return 1;
        }
        if (strlen(FITNESS_DATAS[i].time) != 5){
            printf("Error: invalid file\n");
            return 1;
        }
        if (valid_time(FITNESS_DATAS[i].time) == 1){
            printf("Error: invalid file\n");
            return 1;
        }
        if (valid_date(FITNESS_DATAS[i].date) == 1){
            printf("Error: invalid file\n");
            return 1;
        }
    

    }

    fclose(file);


    sortData(FITNESS_DATAS, rows);


    strcat(filename, ".tsv");
    FILE *output_file = fopen(filename, "w");

    for (int i = 0; i < rows; i++) {
        fprintf(output_file, "%s\t%s\t%d\n", FITNESS_DATAS[i].date, FITNESS_DATAS[i].time, FITNESS_DATAS[i].steps);
    }

    fclose(output_file);

    return 0;
}
