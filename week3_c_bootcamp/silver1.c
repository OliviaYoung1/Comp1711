#include <stdio.h>
int main(){
     int mark;
    printf ("Enter the mark: ");
    scanf ("%d", &mark);
    printf ("The mark to be checked is: %d \n", mark);
    if (mark >= 0 && mark <= 100)
    {
    if (mark >= 70)
    {
        printf("The mark of %d is a distinction \n", mark);
    }
    else if (mark>= 50)
    {
        printf ("The mark of %d is a pass\n", mark);
    }
    else
    {
        printf("The mark of %d is a fail\n", mark);
    }
    }
    else{
        printf("Mark should be between 0 and 100 \n");
    }
}