#include <stdio.h>

/*
 * O(N^3)
 * leetcode 会报Time Limit Exceeded
 */
int subarraySum1(int* nums, int numsSize, int k) {
    int i, j, m, this_sum, sums = 0;
    for(i = 0; i < numsSize; i++)
        for(j = i; j < numsSize; j++)
        {
            this_sum = 0;
            for(m = i; m <= j; m++)
            {
                this_sum += nums[m];
            }
            if(this_sum == k)
                sums += 1;
        }
    return sums;
}

/*
 * O(N^2)
 * 可以通过了
 */
int subarraySum2(int* nums, int numsSize, int k) {
    int i, j, this_sum, sums = 0;
    for(i = 0; i < numsSize; i++)
    {
        this_sum = 0;
        for(j = i; j < numsSize; j++)
        {
            this_sum += nums[j];
            if(this_sum == k)
                sums += 1;
        }
    }
    return sums;
}

/*
 * O(Nlog(N))
 */
int subarraySum3(int* nums, int numsSize, int k) {
    int i, j, this_sum, sums = 0;
    for(i = 0; i < numsSize; i++)
    {
        this_sum = 0;
        for(j = i; j < numsSize; j++)
        {
            this_sum += nums[j];
            if(this_sum == k)
                sums += 1;
        }
    }
    return sums;
}

int main(void)
{
    int nums[] = {1, 1, 1};
    printf("%d\n", subarraySum2(nums, 3, 2));
    return 0;
}
