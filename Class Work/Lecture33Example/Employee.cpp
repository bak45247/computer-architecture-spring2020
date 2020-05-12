// Boston KJ
// Lecture 33 Exercise (Structs)

#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"

int main()
{
    Employee *pE1 = (Employee*)malloc(sizeof(Employee));
    Employee *pE2 = (Employee*)malloc(sizeof(Employee));

    setValues(pE1, 111111111, 10.43, 35);
    setValues(pE2, 222222222, 7.65, 45);

    printf("Employee %d weekly pay: %lf\n", pE1->id, weeklyPay(pE1));
    printf("Employee %d weekly pay: %lf\n", pE2->id, weeklyPay(pE2));

    if(weeklyPay(pE1) > weeklyPay(pE2))
        printf("Employee %d made more this week", pE1->id);
    else
        printf("Employee %d made more this week", pE2->id);

    free(pE1);
    free(pE2);

    return 0;
}

Employee *setValues(Employee *pE, int id, double payRate, int hoursWorked)
{
    pE->id = id;
    pE->payRate = payRate;
    pE->hoursWorked = hoursWorked;

    return pE;
}

double weeklyPay(Employee *pE)
{
    return pE->hoursWorked * pE->payRate;
}