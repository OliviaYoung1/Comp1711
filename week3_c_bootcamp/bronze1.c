#include <stdio.h>
int main(){
    int number;
    printf ("Enter the number: ");
    scanf ("%d", &number);
    if (number == 0)
    {
        printf("Zero");
    }
    else if (number > 0)
    {
        printf("positive");
    }
    else{
        printf("negative");
    }
    return 0;
}