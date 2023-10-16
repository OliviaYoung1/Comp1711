#include <stdio.h>
int main(){
    int temp;
    printf ("Enter the temp: ");
    scanf ("%d", &temp);
    if (temp >= -10 && temp <= 40)
    {
        printf("In range");
    }
    else
    {
        printf("Not in range");
    }
    return 0;
}