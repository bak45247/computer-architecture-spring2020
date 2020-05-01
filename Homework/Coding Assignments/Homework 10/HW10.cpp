// HW 10 Shell
// Name: 

#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void printArray(int **matrix, int n, int m);
int** populateArray(int n, int m, int seed);
int **subsampleArray(int **matrix, int n, int m, int s);
void freeArray(int **matrix, int n);

int main()
{
	int n = 0, m = 0, s = 0, seed = 0;
	printf("Enter the seed: ");
	scanf("%d", &seed);

	printf("Enter the number of sequences: ");
	scanf("%d", &n);
	printf("Enter the number of readings per sequence: ");
	scanf("%d", &m);
	int **array = populateArray(n, m, seed);
	printArray(array, n, m);
	printf("Enter the subsampling factor: ");
	scanf("%d", &s);
	int **subsampled = subsampleArray(array, n, m, s);
	printArray(subsampled, n, s);
	freeArray(array, n);
	freeArray(subsampled, n);
	return 0;
}

void printArray(int** matrix, int n, int m)
{
    printf("Rows: %d, Columns: %d\n", n, m);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d\t", matrix[i][j]); // printing each index, tab separated
        }
        printf("\n"); // newline for clarity
    }
}

int** populateArray(int n, int m, int seed)
{
    srand(seed); // intializing the random numbers with the seed sent

    int** matrix = (int**)malloc(n*sizeof(int*)); // intitializing the "outside" of the array
    for(int i = 0; i < n; i++)
    {
        matrix[i] = (int*)malloc(m*sizeof(int)); // initializing each inside part
        for(int j = 0; j < m; j++) // filling the columns with randoms numbers biased by seed
        {
            matrix[i][j] = rand() % 100 - 50;
        }
    }

    return matrix;
}

int** subsampleArray(int **matrix, int n, int m, int s)
{
    int** subsample = (int**)malloc(n*sizeof(int*));
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        subsample[i] = (int*) malloc((s) * sizeof(int*));
        for(int j = 0; j < s; j++)
        {
            for(int k = j; k < (m - s + 1 + j); k++) // going ahead by m-s+j+1 and adding them to a sum
                sum += matrix[i][k];
            
            subsample[i][j] = sum / (m - s + 1); // placing the average into [i][j] of the subsample array
        }
        sum = 0; // reset sum
    }
    return subsample;
}

void freeArray(int** matrix, int n)
{
    for(int i = 0; i < n; i++)
        free(matrix[i]); // freeing each column

    free(matrix); // freeing the outside of the array
}