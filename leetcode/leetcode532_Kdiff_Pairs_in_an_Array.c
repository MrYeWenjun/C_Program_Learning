#include <stdio.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

int findPairs(int* nums, int numsSize, int k) {
	    
}

int main(void)
{
	int nums[] = {1, 2, 3, 4};
	int numsSize = LENGTH(nums);
	int k = 0;
	printf("%d\n", findPairs(nums, numsSize, k));
	return 0;
}
