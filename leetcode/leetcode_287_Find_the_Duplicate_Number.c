#include <stdio.h>

int findDuplicate(int* nums, int numsSize) {
    int i, j;
    for(i = 0; i < numsSize; i++)
        for(j = i + 1; j < numsSize; j++){
            if(nums[i] == nums[j]){
                i = numsSize;
                break;
            }
        }
    return nums[j];
}

int main(void){
    int nums[] = {1,3,4,5,2,1};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    printf("%d\n", findDuplicate(nums, nums_size));
    return 0;
}
