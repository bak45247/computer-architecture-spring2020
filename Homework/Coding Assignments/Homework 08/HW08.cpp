// Homework 8 - Cache Addressing
// Boston KJ

#include <iostream>
#include <cmath>

int main()
{
    int mainBlocks = 0;
    int cacheLines = 0;
    int lbSize = 0;
    int numSets = 0;

    printf("Enter the number of Blocks in Main Memory: ");
    scanf("%d", &mainBlocks);

    printf("Enter the Number of Lines in Cache: ");
    scanf("%d", &cacheLines);

    printf("Enter the size of the Line/Block: ");
    scanf("%d", &lbSize);

    int mainWords = mainBlocks * lbSize;
    int cacheWords = cacheLines * lbSize;

    printf("The number of words in Main Memory: %d\n", mainWords);
    printf("The number of words in Cache: %d\n", cacheWords);

    printf("Enter the size of a set: ");
    scanf("%d", &numSets);

    int setSize = cacheLines / numSets;

    printf("The size of a set is: %d\n", setSize);

    int address = 0;
    printf("Enter the memory address: ");
    scanf("%d", &address);

    while(address > -1)
    {
        if(address > mainWords)
            printf("This is not a valid Memory Address\n");
        else
        {
            printf("Associative: Tag: %d Offset within line: %d\n", address / lbSize, address % lbSize);
            printf("Direct: Tag: %d Line: %d Offset within line: %d\n", address % lbSize % 10, address / lbSize, address % lbSize);
            printf("Associative: Tag: %d Set: %d Offset within line: %d\n", address / lbSize / setSize, address / lbSize % setSize, address % setSize);

        }
        printf("Enter the memory address: ");
        scanf("%d", &address);
    }
    printf("Done\n\n\n");
}