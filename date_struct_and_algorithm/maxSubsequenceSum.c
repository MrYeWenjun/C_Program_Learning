/*
最大子序列和问题，求整数序列的最大子序列的和
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 1000               //序列长度
#define MY_RAND_MAX 100        //序列的范围(-RAND_MAX, +RAND_MAX)

//算法一,O(N^3)
int MaxSubsequenceSum1(const int A[], int N)
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


//算法二，O(N^2)
int MaxSubsequenceSum2(const int A[], int N)
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


//算法三，分治，O(NlogN)
int Max3(int num1, int num2, int num3)
{
    int temp = num1 > num2? num1:num2;
    return temp > num3? temp:num3;
}

static int MaxSubSum(const int A[], int left, int right)
{
    int max_left_sum, max_right_sum;
    int max_left_border_sum, max_right_border_sum;
    int left_border_sum, right_border_sum;
    int center, i;

    if(left == right)
    {
        if(A[left] > 0)
            return A[left];
        else
            return 0;
    }

    center = (left + right) / 2;
    max_left_sum = MaxSubSum(A, left, center);
    max_right_sum = MaxSubSum(A, center + 1, right);

    max_left_border_sum = 0, left_border_sum = 0;
    for(i = center; i >= left; i--)
    {
        left_border_sum += A[i];
        max_left_border_sum = left_border_sum > max_left_border_sum?
            left_border_sum:max_left_border_sum;
    }

    max_right_border_sum = 0, right_border_sum = 0;
    for(i = center + 1; i <= right; i++)
    {
        right_border_sum += A[i];
        max_right_border_sum = right_border_sum > max_right_border_sum?
            right_border_sum:max_right_border_sum;
    }

    return Max3(max_left_sum, max_right_sum,
                max_left_border_sum + max_right_border_sum);

}

int MaxSubsequenceSum3(const int A[], int N)
{
    return MaxSubSum(A, 0, N-1);
}

//算法四
int MaxSubsequenceSum4(const int A[], int N)
{
    int this_sum, max_sum, i;
    this_sum = max_sum = 0;
    for(i = 0; i < N; i++)
    {
        this_sum += A[i];
        if(this_sum > max_sum)
            max_sum = this_sum;
        else if(this_sum < 0)
            this_sum = 0;
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

    max_sum = MaxSubsequenceSum1(A, NUM);
    printf("\n%d\n", max_sum);

    max_sum = MaxSubsequenceSum2(A, NUM);
    printf("\n%d\n", max_sum);

    max_sum = MaxSubsequenceSum3(A, NUM);
    printf("\n%d\n", max_sum);

    max_sum = MaxSubsequenceSum4(A, NUM);
    printf("\n%d\n", max_sum);
    return 0;
}
