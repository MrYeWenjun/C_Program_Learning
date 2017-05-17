#include <stdio.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int current_count, tmp_count, i;
    current_count = tmp_count = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == 1){
            tmp_count ++;
        }else{
            current_count = current_count > tmp_count?current_count:tmp_count;
            tmp_count = 0;
        }
    }
    return current_count = current_count > tmp_count?current_count:tmp_count;
}

int main(void)
{   int nums[] = {1, 1, 1, 1, 0, 1, 1, 1};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", findMaxConsecutiveOnes(nums, nums_size));
    return 0;
}
