#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int rows = 2;
    int cols = 3;
    int **p;
    int i, j;
    /* 不连续分贝
    p = (int**) malloc(sizeof(int*) * rows);

    for(i = 0; i < rows; i++)
        p[i] = (int*) malloc(sizeof(int) * cols);
        */

    p = (int**) malloc(sizeof(int*) * rows);
    p[0] = (int*) malloc(sizeof(int) * rows * cols);

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            p[i][j] = i * 3 + j;

    return 0;
}
