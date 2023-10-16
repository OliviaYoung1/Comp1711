#include <stdio.h>
int main(){
    int choice;
    printf ("Menu: 0)pizza, 1)pasta, 2)sausage, 3)bread, 4)fish");
    scanf ("%d", &choice);
    switch(choice)
    {
        case 0: printf("You have chose pizza \n");
        break;
        case 1: printf("You have chose pasta \n");
        break;
        case 2: printf("You have chose sausage \n");
        break;
        case 3: printf("You have chose bread \n");
        break;
        case 4: printf("You have chose fish \n");
        break;
        default: printf("Thats not an option");
    
    }

}