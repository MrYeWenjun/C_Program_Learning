/*
��������к����⣬���������е���������еĺ�
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10000               //���г���
#define MY_RAND_MAX 100        //���еķ�Χ(-RAND_MAX, +RAND_MAX)
/*
//�㷨һ,O(N^3)
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

//�㷨����O(N^2)
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
    for(i = 0; i < NUM; i++)                //����������в���ӡ
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
