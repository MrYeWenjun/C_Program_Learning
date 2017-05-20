#include <stdio.h>
#include <limits.h>

int thirdMax(int* nums, int numsSize) {
    long long max, second_max, third_max;
    max = second_max = third_max = LLONG_MIN;
    int i;
    for(i = 0; i < numsSize; i++){
            while(nums[i] != max && nums[i] != second_max && nums[i] != third_max){
                if(nums[i] > max){
                    third_max = second_max;
                    second_max = max;
                    max = nums[i];
                }else if(nums[i] > second_max){
                    third_max = second_max;
                    second_max = nums[i];
                }else if(nums[i] > third_max){
                    third_max = nums[i];
                }else{
                    break;
                }
            }
    }
    return third_max == LLONG_MIN? max: third_max;
}

int main(void){
    int nums[] = {5,2,4,1,3,6,0};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    printf("Third max of nums is %d\n", thirdMax(nums, nums_size));
    printf("%d\n", INT_MIN);
    printf("%ld\n", LONG_MIN);
    printf("%I64d\n", LLONG_MIN);
    return 0;
}
