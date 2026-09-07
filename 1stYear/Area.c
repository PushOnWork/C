#include<stdio.h>
int main() {
    int r,l,b;
    float area;
    printf("Enter radius of circle, length and breadth of rectangle:");
    scanf("%d %d %d",&r,&l,&b);
    area = 3.14*r*r;
    printf("Area of circle: %f\n",area);
    area = l*b;
    printf("Area of rectangle: %f\n",area);
    return 0;
}