#include <stdio.h>
int main(){
    int number=0 ;
    if (number >= 0 && number <= 100)
    {
    while (number != -1)
    {
            printf ("Enter the number: ");
            scanf ("%d", &number);
    }
    }
    else 
    {
        printf("Not in range");
    }
    return 0;
}