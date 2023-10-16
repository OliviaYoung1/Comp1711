#include <stdio.h>
int main(){
     int number;
    printf ("Enter the number: ");
    scanf ("%d", &number);
    if (number%4 == 0 && number%5 == 0)
    {
        printf("Divisible by 4 and 5");
    }
    else
    {
        printf("not divisible by 4&5");
    }
    return 0;
}