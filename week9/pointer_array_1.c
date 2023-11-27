#include <stdio.h>

int main()
{
    //vector is a pointer to its first element
    int vector[5] = {1,2,3,4,5};

    int* address;
    //assigns the address of the first element of the array vector to address
    address = vector; 

    printf("\n \n address = %p\n", address);

    printf( " vector = %p\n\n",vector);

    printf ("address[0] = %d  ,  vector[0] = %d  \n\n",address[0],vector[0]);

}