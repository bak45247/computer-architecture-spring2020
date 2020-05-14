//Boston KJ
// Lecture 36 File IO codealong

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Command line arguments
    printf("Number of arguments: %d\n", argc); // argc is the number of arguments passed in
    for(int i = 0; i < argc; i++)
    {
        // converting arguments to their 'numerical' counterparts from the strings they're passed in as
        int x = atoi(argv[i]); // converting the argument to an integer
        double y = atof(argv[i]); // converting the argument to a float
        printf("%d: %d %lf %s\n", i, x, y, argv[i]); // argv contains the arguments as strings
    }

    // Opening the connection to the file
    // argv[1] = number of animals
    // argv[2] = name of input file
    // argv[3] = name of output file
    FILE *animals = fopen(argv[2], "r"); // "r" signifies that we are opening in read mode
    FILE *output = fopen(argv[3], "w");
    /**
     * "w" means we open in write mode
     * if the file doesn't exist, it is created
     * if the file does exist, it's deleted then recreated
    **/

    int length = 0;
    char name[100];
    int nameLength = 0;

    // Reading all the animals
    for(int i = 0; i < atoi(argv[1]); i++)
    {
        printf("Animal number: %d\n", i);
        fscanf(animals, "%d", &length);
        fscanf(animals, "%s", name);
        fscanf(animals, "%d", &nameLength);

        printf("Information: %d %s %d\n", length, name, nameLength);
        fprintf(output, "Information: %d %s %d\n", length, name, nameLength); // writing to our output file
    }

    // Closing the connection to the file
    fclose(animals);
    fclose(output);
    return 0;
}