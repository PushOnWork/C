#include<stdio.h>
int main() {
    int elec,math,ai,mech,env;
    printf("Enter marks in each subject:\n");
    scanf("%d %d %d %d %d",&elec,&math,&ai,&mech,&env);
    printf("Total marks: %d\n",elec+math+ai+mech+env);
    float percentage = ((elec+math+ai+mech+env)*100.0)/500.0;
    printf("Percentage: %f\n",percentage);
    return 0;
}