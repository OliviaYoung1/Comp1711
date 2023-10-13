#include <stdio.h>
int main(){
    float width, length, area;
    printf("Enter width");
    scanf("%f", &width);
    printf("Enter length");
    scanf("%f", &length);
    area = width * length;
    printf("The area of the rectangle is %.2f\n" , area);
    return 0;
}