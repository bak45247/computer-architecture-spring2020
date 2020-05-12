// Boston KJ
// Circle.cpp

#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include "Circle.h"

void printCircleWithStruct(CircleWithStruct c)
{
    printf("Circle radius: %lf, center: %d %d\n", c.radius, c.centerS.x, c.centerS.y);
}

void printCircleWithPointer(CircleWithPointer c)
{
    printf("Circle radius: %lf, center %d %d\n", c.radius, c.centerP->x, c.centerP->y);
}

double findDistance(CircleWithPointer *pC)
{
    return sqrt((pC->centerP->x * pC->centerP->x) + (pC->centerP->y * pC->centerP->y));
}

double findDistance(CircleWithStruct *pC)
{
    return sqrt((pC->centerS.x * pC->centerS.x) + (pC->centerS.y * pC->centerS.y));
}
