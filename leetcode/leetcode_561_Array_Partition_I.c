#include <stdio.h>

int arrayPairSum(int* nums, int numsSize) {
    int i, j, sum = 0;
    int current_min, index_of_min;
    for(i = 0; i < numsSize; i++)
    {
        current_min = nums[i];
        index_of_min = i;
        for(j = i + 1; j < numsSize; j++)
        {
            if(current_min > nums[j])
            {
                current_min = nums[j];
                index_of_min = j;
            }
        }
        if(index_of_min != i)
        {
            nums[index_of_min] = nums[i];
            nums[i] = current_min;
        }
    }

    for(i = 0; i < numsSize; i += 2)
        sum += nums[i];
    return sum;
}

int main(void)
{
    int nums[] = {1,2,3,4};
    printf("%d\n", arrayPairSum(nums, 4));
    return 0;
}
