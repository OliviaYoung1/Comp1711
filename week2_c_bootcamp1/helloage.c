#include <stdio.h>
int main(){
    int age;
    printf("Hello please enter your age:");
    scanf("%d", &age); //& is a pointer to where age is kept in mem, for nums
    printf("Your age is %d\n", age);
    return 0; 
}