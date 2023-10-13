#include <stdio.h>
int main(){
    char mystring[]= "Hello";
    int a;
    for (a=5; a >= 0; a--)
    {
        printf("%c\n", mystring[a]);
    }
    return 0;
}