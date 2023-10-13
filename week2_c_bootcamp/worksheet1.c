#include <stdio.h>
int main(){
//task 1
    //printf("Hello World \n");

//task 2
    //int num1, num2, num3;
    //printf("Enter a number");
    //scanf("%d",&num1);
    //("Enter a number");
   // scanf("%d", &num2);
   // num3 = num1 +num2;
    //printf("%d\n", num3);

//task 4
    //float radius, pi, area;
    //pi = 3.14;
    //printf("Enter the radius");
    //scanf("%f",&radius);
    //area = pi * radius * radius;
    //printf("Area is %f\n", area);

//task 5
    //int val1, val2, temp1, temp2;
    //printf("Enter val 1");
    //scanf("%d",&val1);
    //("Enter a val 2");
    //scanf("%d", &val2);
    //temp1 = val1;
    //temp2 = val2;
    //val1 = temp2;
    //val2 = temp1;
    //printf("Val1 is now %d, val2 is now %d\n",val1, val2);

 //task 6
    //int number;
        //printf("Enter an integer: ");
        //scanf("%d", &number);

        //if  (number%2 == 0) {
            //printf("%d is an even integer.",number);
        //}
        //else {
            //printf("%d is an odd integer.",number);
        //}

// task 8
        int number, factorial=1, i;
        printf("Enter an integer: ");
        scanf("%d", &number);
        for (int i = 1; i < number+1 ; i++)
        {
            factorial = factorial * i;
        }
        printf("The factorial is %d\n", factorial);
    return 0;
}