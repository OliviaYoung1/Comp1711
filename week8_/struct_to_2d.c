#include <stdio.h>
#define N_STUDENTS 4
#define N_MODULES 3

typedef struct {
    char name[50];
    int id;
    float GPA;
    int procedural_prog;
    int intro_to_prog;
    int operating_systems;
} Student;

void extractAndStore(Student Students[], int extractedData[][N_MODULES]){
    for (int i = 0; i < N_STUDENTS; i++){
        extractedData[i][0] =Students[i].procedural_prog;
        extractedData[i][1] =Students[i].intro_to_prog;
        extractedData[i][2] =Students[i].operating_systems;
    }
}
int main(){
    Student Students[N_STUDENTS] = {
        {"Alex Turner", 2306456, 3.5, 78, 82, 89},
        {"Bob Williams", 2385679, 3.9, 100, 85, 92},
        {"Sophia Mendes", 2374068, 3.7, 93, 90, 87},
        {"Laura Cerroni", 2398452, 3.2, 65, 70, 80}
    };

    int extractedData[N_STUDENTS][N_MODULES];
    extractAndStore(Students, extractedData);

    printf("Extracted Data:\n");
    for (int i = 0; i < N_STUDENTS; ++i) {
        printf("Student %d: %d, %d, %d\n", i + 1, extractedData[i][0],extractedData[i][1], extractedData[i][2]);
        }
        return 0;

}