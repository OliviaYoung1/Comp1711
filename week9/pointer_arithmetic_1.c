#include <stdio.h>

int main()
{
    int vector[5] = {11,13,17, 23 , 31};

    int* address = vector;

    printf ( "\nAddress[0] = %d\n", *address);
    //note the brackets
    //adding to a pointer adds t hte size of the item the pointer points to
    printf ( "\nAddress[1] = %d\n", *(address+1));
    printf ( "\nAddress[1] = %d\n", address[1]);
    printf ("\n Address[2] = %d\n", *(address+2));

    

}