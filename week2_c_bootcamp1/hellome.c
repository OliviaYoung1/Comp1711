#include <stdio.h>
int main(){
    char name[15]; //variable called name upto 15 chars

    printf("Hello please enter your name");
    scanf("%s",name); //scans the keyboad- s is string, stores in name
    printf("Your name is %s\n ", name); //subs in name wit %s format
    // \n is new line
    return 0;
}