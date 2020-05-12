// Boston KJ
// Lecture 33 Code Along
// Main

#include <stdio.h>
#include <stdlib.h>
#include "Student.h"

int main()
{
    // Static Struct creation
    Student s;
    s.gpa = 3.4;
    s.ID = 1111;
    s.yearInSchool = 'F';

    printf("Student information: %d %c %lf\n", s.ID, s.yearInSchool, s.gpa);

    // Dynamic Struct creation
    Student *pS = (Student*)malloc(sizeof(Student));
    pS->ID = 1234;
    pS->gpa = 4.0;
    pS->yearInSchool = 'S';

    printf("Student information: %d %c %lf\n", pS->ID, pS->yearInSchool, pS->gpa);
    // free(pS);

    return 0;
}