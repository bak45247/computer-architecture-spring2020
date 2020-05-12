// Homework 6 - Quadratic Equation Bisection Method
// Boston KJ

#include <iostream>
#include <cmath>

int main()
{
    double upper = 0, lower = 0, t = 0, a = 0, b = 0, c = 0;
    // upper - upper threshold, lower - lower threshold, t - threshold of difference
    // a - x^2 coefficient, b - x coefficient, c - constant

    // getting required variables
    printf("Enter the lower bound of root: ");
    scanf("%lf", &lower);

    printf("Enter the upper bound of root: ");
    scanf("%lf", &upper);

    printf("Enter the difference threshold: ");
    scanf("%lf", &t);

    printf("Enter the coefficient of x^2: ");
    scanf("%lf", &a);

    printf("Enter the coefficient of x: ");
    scanf("%lf", &b);

    printf("Enter the constant: ");
    scanf("%lf", &c);

    // doing the math
    double x = (upper + lower) / 2;
    double calculation = 0; // this is the result of f(x)
    int counter = 0;
    while(upper - lower > t)
    {
        calculation = a * (x * x) + b * x + c;
        if(calculation < 0)
        {
            printf("%lf  %lf  %lf  %lf  %lf  Changing lower\n", lower, upper, x, calculation, abs(upper - lower));
            lower = x;
        }
        else
        {
            printf("%lf  %lf  %lf  %lf  %lf  Changing upper\n", lower, upper, x, calculation, abs(upper - lower));
            upper = x;
        }
        counter += 1;
        x = (upper + lower) / 2;
    }

    printf("The root is found at ~%lf\n", x);
    printf("The number of iterations is: %d\n", counter);
}