/*
    I will be using the same logic as implememted in the pthread program
*/

/*
    OpenMP Matrix Multiplication
    Usage: ./mat_mul_omp <number of thread> <rows of matrix A> <columns of matrix A> <rows of matrix B> <columns of matrix B>
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

// number of rows and columns for each of the matrices
int row1, col1;
int row2, col2;

// global matrices to be multiplied
double *matrixA;
double *matrixB;
double *matrixC;

int thread_count;

// this function returns a random double between the given range
double get_random_number(double min, double max)
{
    double number = (double)rand() / (double)RAND_MAX;
    return min + number * (max - min);
}

int main(int argc, char *argv[])
{
    if (argc != 6)
    {
        printf("Enter all the arguments for the program\n");
        printf("Usage: %s <thread_count> <row1> <col1> <row2> <col2>\n", argv[0]);
        return 1;
    }

    // Seed for the random number generator
    srand(time(NULL));

    // initializing the values for the thread count and dimensions of the matrices
    thread_count = atoi(argv[1]);
    row1 = atoi(argv[2]);
    col1 = atoi(argv[3]);
    row2 = atoi(argv[4]);
    col2 = atoi(argv[5]);

    if (col1 != row2)
    {
        printf("Dimension Error!!!!!!!\n");
        printf("Cannot multiply these two matrices\n");
        return 1;
    }

    // Allocating memory for the matrices (No thread_handle needed for OpenMP)
    matrixA = malloc(row1 * col1 * sizeof(double));
    matrixB = malloc(row2 * col2 * sizeof(double));
    matrixC = malloc(row1 * col2 * sizeof(double));

    // Populating the matrices with random numbers
    // first matrix
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            matrixA[i * col1 + j] = get_random_number(0.0, 10.0);
        }
    }
    // second matrix
    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            matrixB[i * col2 + j] = get_random_number(0.0, 10.0);
        }
    }

    // below code was use to test the matrix data
    //  If the matrices are two large a=only top 5 x 5 submatrix will be shown
    int r, c;
    printf("First Matrix------\n");

    if (row1 > 5 || col1 > 5)
    {
        printf("(Only showing up to top 5x5 submatrix)\n");
    }
    r = (row1 > 5) ? 5 : row1;
    c = (col2 > 5) ? 5 : col1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%lf\t", matrixA[i * col1 + j]);
        }
        printf("\n");
    }

    printf("\n\nSecond Matrix------\n");

    if (row2 > 5 || col2 > 5)
    {
        printf("(Only showing up to top 5x5 submatrix)\n");
    }
    r = (row2 > 5) ? 5 : row2;
    c = (col2 > 5) ? 5 : col2;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%lf\t", matrixB[i * col2 + j]);
        }
        printf("\n");
    }

    #pragma omp parallel for num_threads(thread_count)
    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            matrixC[i * col2 + j] = 0.0;
            for (int k = 0; k < col1; k++)
            {
                matrixC[i * col2 + j] += matrixA[i * col1 + k] * matrixB[k * col2 + j];
            }
        }
    }


    printf("\nFinal Matrix:\n");

    if (row1 > 5 || col2 > 5)
    {
        printf("(Only showing up to top 5x5 submatrix)\n");
    }

    r = (row1 > 5) ? 5 : row1;
    c = (col2 > 5) ? 5 : col2;

    for (int i = 0; i < r ; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%lf\t", matrixC[i * col2 + j]);
        }
        printf("\n");
    }


    // Cleaning
    free(matrixA);
    free(matrixB);
    free(matrixC);

    return 0;
}