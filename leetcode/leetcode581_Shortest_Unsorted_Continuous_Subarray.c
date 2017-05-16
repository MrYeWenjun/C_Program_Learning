#include <stdio.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

int findUnsortedSubarray(int* nums, int numsSize) {
	int min_index, max_index;
	max_index = min_index = 0;
	int i, j;
	for(i = 0; i < numsSize; i++)
		for(j = i + 1; j < numsSize; j++)
		{
			if(nums[i] > nums[j])
			{
				min_index = i;
				i = numsSize;
				break;
			}
		}
	for(i = numsSize - 1; i >= 0; i--)
		for(j = i - 1; j >= 0; j--)
		{
			if(nums[i] < nums[j])
			{
				max_index = i;
				i = -1;
				break;
			}
		}
	 printf("%d-%d\n", max_index, min_index);
	return max_index > min_index ? max_index - min_index + 1: 0;
}

int main()
{
	int nums[] = {2, 1};
	int numsSize = LENGTH(nums);
	printf("%d\n", findUnsortedSubarray(nums, numsSize));
	return 0;
}
