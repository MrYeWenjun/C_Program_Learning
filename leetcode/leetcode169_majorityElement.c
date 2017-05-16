#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int cnt = 0 , i = 0, rtn;
    for(i = 0; i < numsSize; ++i)
    {
        if(cnt == 0)
            rtn = nums[i];
        if(rtn == nums[i])
            ++cnt;
        else --cnt;
    }
    return rtn;
}

int main(void)
{
    int nums[10] = {10,9,8,1,1,1,1,1,1,2};
    int rtn = majorityElement(nums, 10);
    printf("%d\n", rtn);
    return 0;
}
