#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    int i;
    if(numsRowSize * numsColSize != r * c)
    {
        r = numsRowSize;
        c = numsColSize;
    }
    *returnSize = r;
    printf("returnSize = %d\n", *returnSize);
    int** return_array = (int**) malloc(sizeof(int*) * r);
    *columnSizes = (int*) malloc(sizeof(int) * r);
    //test
    for(i = 0; i < r; i++)
        printf("%d\n", (*columnSizes)[i]);

    for(i = 0; i < r; i++)
    {
        return_array[i] = (int*) malloc(sizeof(int) * c);
        (*columnSizes)[i] = c;
    }
    for(i = 0; i < numsRowSize * numsColSize; i++)
    {
        return_array[i/c][i%c] = nums[i/numsColSize][i%numsColSize];
    }
    return return_array;
}

int main( void )
{
    int i, j;
    int m = 3;
    int n = 4;
    int r = 2;
    int c = 6;

    int **nums = (int**) malloc(sizeof(int*) * m);
    for(i = 0; i < m; i++)
        nums[i] = (int*) malloc(sizeof(int) * n);

    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++)
            nums[i][j] = i * m + j;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("[%d][%d] = %d    ", i, j, nums[i][j]);
        }
        printf("\n");
    }

    int* columnSizes;
    int returnSize;
    int** return_array = matrixReshape(nums, m, n, r, c, &columnSizes, &returnSize);

    for(i = 0;i < sizeof(columnSizes) / sizeof(columnSizes[0]); i++)
        printf("columnSizes[%d] = %d   ", i, columnSizes[i]);
    printf("\n");
    printf("returnSize = %d\n",returnSize);

    for(i = 0; i < returnSize; i++)
        {
            for(j = 0; j < columnSizes[i]; j++)
            {
                printf("[%d][%d] = %d    ", i, j, return_array[i][j]);
            }
            printf("\n");
        }
    return 0;
}
