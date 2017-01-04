/*
最大子序列和问题，求整数序列的最大子序列的和
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10000               //序列长度
#define MY_RAND_MAX 100        //序列的范围(-RAND_MAX, +RAND_MAX)
/*
//算法一,O(N^3)
int MaxSubsequenceSum(const int A[], int N)
{
    int this_sum, max_sum, i, j, k;
    max_sum = 0;
    for(i = 0; i < N; i++)
    {
        for(j = i; j < N; j++)
        {
            this_sum = 0;
            for(k = i; k < j; k++)
            {
                this_sum += A[k];
            }
            if(this_sum > max_sum)
            {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}
*/

//算法二，O(N^2)
int MaxSubsequenceSum(const int A[], int N)
{
    int this_sum, max_sum, i, j;
    max_sum = 0;
    for(i = 0; i < N; i++)
    {
        this_sum = 0;
        for(j = i; j < N; j++)
        {
            this_sum += A[j];
            if(this_sum > max_sum)
            {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}

int main()
{
    int A[NUM];
    srand((unsigned int) time(0));
    int max_sum, i;
    for(i = 0; i < NUM; i++)                //随机产生序列并打印
    {
        A[i] = rand() % (MY_RAND_MAX * 2) - MY_RAND_MAX;
        printf("%4d", A[i]);
        if(i % 10 == 9)
            printf("\n");
    }

    max_sum = MaxSubsequenceSum(A, NUM);
    printf("\n%d\n", max_sum);

    return 0;
}
