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

void quick_sort(int* nums, int start, int end)
{
	int position;
	if(start < end)
	{
		position = partition(nums, start, end);
		quick_sort(nums, start, position - 1);
		quick_sort(nums, position + 1, end);
	}
}
void show_nums(int* nums, int nums_size)
{
	int i;
	for(i = 0; i < nums_size; i++)
	{
		printf("%3d",nums[i]);
	}
	printf("\n");
}
int main ()
{
	int nums[] = {3, 1, 4,1};
	int nums_size = LENGTH(nums);
	printf("nums_size = %d\n", nums_size);
	show_nums(nums, nums_size);
	quick_sort(nums, 0, nums_size - 1);
	show_nums(nums, nums_size);
    return 0;
}
