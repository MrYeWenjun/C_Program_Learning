#include <stdio.h>

int minMoves(int* nums, int numsSize) {
    if (numsSize == 1)
        return 0;
    int min = nums[1];
    int i, rtn = 0, sum = 0;
    for(i = 0; i < numsSize; i++)
    {
        min = nums[i] < min? nums[i]: min;
        sum +=nums[i];
    }
    return rtn = sum - min * numsSize;
}

int main()
{
    int nums[] = {1};
    int n = 1;
    printf("%d\n", minMoves(nums, n));
    return 0;
}
