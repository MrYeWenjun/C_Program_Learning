
#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* a, int* b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a = *a^*b;
}

void print_array(int* nums, int nums_size)
{
    int i;
    for(i = 0; i < nums_size; i++)
    {
        printf("%3d", nums[i]);
    }
    printf("\n");
}

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize)
{
    int* return_ptr = malloc(sizeof(int) * numsSize);
    *returnSize = 0;
    int i;
    for(i = 0; i < numsSize; i++)
    {
        while(nums[i] > 0 && nums[i] != i + 1)
        {
            if(nums[i] == nums[nums[i] - 1])
            {
                nums[i] = 0;
                break;
            }
            else
            {
                swap(&nums[i], &nums[nums[i] - 1]);
            }
        }
    }

    //print_array(nums, numsSize);

    for(i = 0; i < numsSize; i++)
    {

        if(nums[i] == 0)
        {
            return_ptr[*returnSize] = i + 1;
            *returnSize += 1;
        }
    }

    return return_ptr;
}

int main(void)
{

    int nums[] = {3, 3, 2, 7, 8, 2, 3, 1};
    int nums_size = sizeof(nums) / sizeof(nums[0]);
    int* return_size = malloc(sizeof(int));
    int* return_ptr = findDisappearedNumbers(nums, nums_size, return_size);
    print_array(return_ptr, *return_size);
    /* test
    int a = 1;
    int b = 2;
    printf("a = %d b = %d\n", a, b);
    swap(&a, &b);
    printf("a = %d b = %d\n", a, b);
    */
    return 0;

}
