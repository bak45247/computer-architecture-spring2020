// Boston KJ
// Code along, types of arrays
// DAD, DAS, SAD, SAS

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

int main()
{
    // Static array, Static objects
    Point saso[10];

    // Dynamic array, static objects
    Point *daso = (Point*)malloc(sizeof(Point) * 10);

    // Static array, Dynamic objects
    Point *sado[10];
    for(int i = 0; i < 10; i++)
    {
        sado[i] = (Point*)malloc(sizeof(Point));
    }

    //Dynamic array, Dynamic objects
    Point **dado = (Point**)malloc(sizeof(Point*) * 10);
    for(int i = 0; i < 10; i++)
    {
        dado[i] = (Point*)malloc(sizeof(Point));
    }

    //freeing memory
    free(daso);

    for(int i = 0; i < 10; i++)
    {
        free(sado[i]);
        free(dado[i]);
    }

    free(dado);

    return 0;
}