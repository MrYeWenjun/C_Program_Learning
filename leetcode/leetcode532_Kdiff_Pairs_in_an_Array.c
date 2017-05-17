#include <stdio.h>

#define LENGTH(x) (sizeof(x) / sizeof(x[0]))

int partition(int* nums, int low, int high)
{
	int key = nums[low];
	while(low < high)
	{
		while(low < high && nums[high] >= key)
		{
			high--;
		}
		if(low < high)
		{
			nums[low++] = nums[high];
		}
		while(low < high && nums[low] <= key)
		{
			low++;
		}
		if(low < high)
		{
			nums[high--] = nums[low];
		}
	}
	nums[low] = key;
	return low;
}

void quick_sort(int* nums, int start, int stop)
{
	int position;
	if(start < stop)
	{
		position = partition(nums, start, stop);
		quick_sort(nums, start, position - 1);
		quick_sort(nums , position + 1, stop);
	}
}
int findPairs(int* nums, int numsSize, int k) {
	quick_sort(nums, 0, numsSize - 1);
	int i, j, cnt;
	cnt = 0;
	for(i = 0; i < numsSize; i++)
	{
		j = i + 1;
		while(j < numsSize)
		{
			if(nums[i] + k == nums[j])
			{
				cnt++;
				j++;
			}
			else
			{
				j++;
			}
			while(nums[j + 1] == nums[j])	
			{
				j++;
			}
			
		}
		while(nums[i + 1] == nums[i])
		{
			i++;
		}
	}

	return cnt;
}

int main(void)
{
	int nums[] = {1, 1, 1, 1, 1};
	int numsSize = LENGTH(nums);
	int k = 0;
	int i;
	for(i = 0; i < numsSize; i++)
	{
		printf("%3d",nums[i]);
	}
	printf("\n");
	quick_sort(nums, 0, numsSize);
	for(i = 0; i < numsSize; i++)
	{
		printf("%3d",nums[i]);
	}
	printf("\n");

	printf("%d\n", findPairs(nums, numsSize, k));
	return 0;
}
