#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17, 23 , 31};

    int* address = vector;

    printf ( "\nAddress[0] = %d\n", *address);

    //accesses the value first, then increases by 1
    printf ( "\nAddress[1] = %d\n", *address++);
    //increases by one then accesses the value
    printf ("\n Address[2] = %d\n", *++address);

    printf ("\n \n What is happening here?");
}