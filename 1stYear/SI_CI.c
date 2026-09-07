#include<stdio.h>
#include<math.h>
int main() {
    int p,r,t;
    float si,a,ci;
    printf("Enter principal amount, rate of interest and time in years:\n");
    scanf("%d %d %d",&p,&r,&t);
    si = (p*r*t)/100.0;
    a = p*pow((1+r/100.0),t);
    ci = a-p;
    printf("Simple Interest: %f\n",si);
    printf("Compound Interest: %f\n",ci);
    return 0;
}