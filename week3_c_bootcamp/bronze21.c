#include <stdio.h>
float circleArea(float radius)
{
    float area = 3.14 * radius * radius;
    return area;
}

int main(){
    float r;
    printf("Enter radius");
    scanf("%f", &r);
    printf("%f\n", circleArea(r));
    return 0;
    }