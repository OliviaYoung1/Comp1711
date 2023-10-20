#include <stdio.h>
float SphereVolume(float radius)
{
    float vol = 1.3333 * 3.14 * radius * radius * radius;
    return vol;
}

int main(){
    float r;
    printf("Enter radius");
    scanf("%f", &r);
    printf("%f\n", SphereVolume(r));
    return 0;
    }