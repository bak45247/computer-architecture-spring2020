#include "Point.h"

struct CircleWithStruct
{
        double radius;
        Point centerS;
};

struct CircleWithPointer
{
        double radius;
        Point *centerP;
};

void printCircleWithStruct(CircleWithStruct c);
void printCircleWithPointer(CircleWithPointer c);

double findDistance(CircleWithPointer *pC);
double findDistance(CircleWithStruct *pC);
