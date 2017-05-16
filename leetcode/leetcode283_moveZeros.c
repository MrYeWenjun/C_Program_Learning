#include <stdio.h>
/*
void moveZeroes(int* nums, int numsSize) {
    int *pa, *pb;
    pa = nums;
    pb = pa;
    int i = 0, j = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(*pa == 0)
        {
            for(j = i; j < numsSize - 1; j++)
            {
                *pb = *(pb+1);
                pb++;
            }
        *pb = 0;
        }
        if(*pa != 0)
            pa++;
        pb = pa;
    }
}
*/
void moveZeroes(int *nums, int numsSize)
{
    int lastNotZeros = 0;
    int i = 0;
    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] != 0)
        {
            nums[lastNotZeros++] = nums[i];
        }
    }
    for (i = lastNotZeros; i < numsSize; i++)
    {
        nums[i] = 0;
    }
}
int main(void)
{
    int nums[] = {4,2,4,0,0,3,0,5,1,0};
    int i = 0;
    int n = 10;
    moveZeroes(nums, n);
    for(i = 0; i < n; i++)
        printf("%d ", nums[i]);
    return 0;
}
