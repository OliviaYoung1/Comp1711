#include <stdio.h>
#include <stdlib.h>

int main(){
    int array_size;
    printf("\n Input the size of the array = ");
    scanf("%d", &array_size);
    printf("\n\n");
    //malloc(k) allocates at least k bytes of mem
    //malloc returns a void type pointer, which we typecast to int
    int* vector = (int *) malloc(sizeof(int)*array_size);
    if (vector==NULL) {
        printf("Memory allocation failed.\n");
    return 1;
    }
    
    for (int i=0; i<array_size; i++){
        vector[i] = i*i;
        printf ("\nvector[%d] = %d\n", i , vector[i]);
        }
        free(vector);
        }