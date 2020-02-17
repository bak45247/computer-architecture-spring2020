// Homework 4 - Monte Carlo Simulation
// Boston KJ

#include <iostream>
#include <stdlib.h>

int main()
{
    int n;
    int inside = 0;
    int outside = 0;
    double x, y;

    printf("Please enter the number of points ");
    scanf("%d", &n);

    // initiating random using seed 100
    srand(100);

    for (int i = 0; i < n; i++)
    {
        x = (double)rand() / RAND_MAX;
        y = (double)rand() / RAND_MAX;

        double toOrigin = (x * x) + (y * y);

        if (toOrigin <= 1)
            inside += 1;
        else
            outside += 1;
    }

    double estimate = (double)inside / n * 4;

    printf("Total Points: %d\n Number of Points in the quarter circle: %d \n Number of points outside the quarter circle: %d \n Final Estimate: %lf \n", n, inside, outside, estimate);
}