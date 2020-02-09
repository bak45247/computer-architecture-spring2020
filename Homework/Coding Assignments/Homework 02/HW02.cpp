// Homework 02 - Boston KJ
// Intro to C Programming

#include<iostream>

int main()
{
    // geting the inputs
    int first = 0;
    printf("Enter the first resistance: ");
    scanf("%d", &first);

    int second = 0;
    printf("Enter the second resistance: ");
    scanf("%d", &second);

    // doing the math for the resistances
    double series = (double)(first + second);
    double parallel = 1.0 / ((1.0 / first) + (1.0 / second));

    printf("The resistance in series is: %lf\n", series);
    printf("The resistance in parallel is: %lf\n", parallel);

    return 0;
}