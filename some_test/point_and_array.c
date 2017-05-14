#include <stdio.h>
#include <stdlib.h>
void modify_array(int ** array, int array_row, int array_col)
{
    int i, j;
    for(i = 0; i < array_row; i++)
        for(j = 0; j < array_col; j++)
        {
            array[i][j] = 10 + 3 * i + j;
        }
}
void modify_point(int* p)
{
    *p = 5;
}
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c) {
    if( numsRowSize * numsColSize != r * c )
        return nums;
    //columnSizes = ( int ** )malloc( sizeof( int ) * r * c );
    int **return_nums = ( int ** )malloc( sizeof( int * ) * r );
    int i, j;
    for(i = 0; i < r; i++)
        return_nums[i] = (int *) malloc(sizeof(int) * c);
    int row = 0, col = 0;
    for(i = 0; i < numsRowSize; i++)
        for(j = 0; j < numsColSize; j++)
        {
            return_nums[row][col] = nums[i][j];
            if(++col == c)
            {
                row++;
                col = 0;
            }
        }
    return return_nums;
}

int main( void )
{
    int a[2][3] = {{10, 11, 12}, {13, 14, 15}};

    printf("row of a = %d\n",sizeof(a) / sizeof(a[0]));
    printf("col of a = %d\n",sizeof(a[0]) / sizeof(int));

    printf("sizeof(a) = %d\n", sizeof(a));
    printf("sizeof(a[0]) = %d\n", sizeof(a[0]));
    printf("sizeof(a[0][0]) = %d\n", sizeof(a[0][0]));

    printf("a = %p\n", a);
    printf("&a = %p\n", &a);
    printf("&a[0] = %p\n", &a[0]);
    printf("&a[0][0] = %p\n", &a[0][0]);
    printf("&a[0][1] = %p\n", &a[0][1]);

    int *p = a[0];
    printf("sizeof(p) = %d\n", sizeof(p));
    printf("sizeof(p[0]) = %d\n", sizeof(p[0]));
    int i, j;
    for(i = 0; i < 6; i++)
    {
        printf("p[%d] = %d\n", i, p[i]);
        printf("*(p + %d) = %d\n",i ,*(p + i));
    }

    int (*p1)[3];
    printf("sizeof(p1) = %d\n", sizeof(p1));
    p1 = a;
    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            printf("p1[%d][%d] = %d\n",i ,j ,p1[i][j]);
            printf("(*(p1 + %d))[%d] = %d\n", i, j, (*(p1 + i))[j]);
        }

    int **p2;
    p2 = (int **) malloc(sizeof(int *) * 2);
    for(i = 0; i < 2; i++)
        p2[i] = (int *) malloc(sizeof(int) * 3);
    printf("sizeof(p2) = %d\n", sizeof(p2));
    printf("sizeof(p2[0]) = %d\n", sizeof(p2[0]));
    printf("row of p2 = %d\n",sizeof(p2) / sizeof(p2[0]));
    printf("col of p2 = %d\n",sizeof(p2[0]) / sizeof(int));

    modify_array(p2, 2, 3);
    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
        {
            printf("p2[%d][%d] = %d\n", i, j, p2[i][j]);
        }

    int **p3 = matrixReshape(p2, 2, 3, 1, 6);
    for(i = 0; i < 1; i++)
        for(j = 0; j < 6; j++)
        {
            printf("p3[%d][%d] = %d\n", i, j, p3[i][j]);
        }

    int num;
    modify_point(&num);
    printf("*p = %d\n", num);
    return 0;
}
