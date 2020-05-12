// Boston KJ
// Circle Driver

#include <stdio.h>
#include <stdlib.h>
#include "Circle.h"

int main()
{
    // Static circle with struct
    CircleWithStruct sCWS;
    sCWS.radius = 1.0;
    sCWS.centerS.x = 1;
    sCWS.centerS.y = 1;
    printCircleWithStruct(sCWS);

    // dynamic circle with struct
    CircleWithStruct *dCWS = (CircleWithStruct*)malloc(sizeof(CircleWithStruct));
    dCWS->radius = 2.0;
    dCWS->centerS.x = 2;
    dCWS->centerS.y = 2;
    printCircleWithStruct(*dCWS);

    // static circle with pointer
    CircleWithPointer sCWP;
    sCWP.radius = 3.0;
    sCWP.centerP = (Point*)malloc(sizeof(Point));
    sCWP.centerP->x = 3;
    sCWP.centerP->y = 3;
    printCircleWithPointer(sCWP);

    // dynamic circle with pointer
    CircleWithPointer *dCWP = (CircleWithPointer*)malloc(sizeof(CircleWithPointer));
    dCWP->radius = 4.0;
    dCWP->centerP = (Point*)malloc(sizeof(Point));
    dCWP->centerP->x = 4;
    dCWP->centerP->y = 4;
    printCircleWithPointer(*dCWP);

    // distance functions
    printf("Distance to origin: %lf\n", findDistance(dCWP));
    printf("Distance to origin: %lf", findDistance(dCWS));

    // free memory
    free(dCWS);

    free(sCWP.centerP);

    free(dCWP->centerP);
    free(dCWP);
    
    return 0;
}